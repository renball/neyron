#define _USE_MATH_DEFINES 
#include <cmath>
#include <math.h>
#include "math.h"
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdbool.h>
#include "gr.h"
#include <Windows.h>
#include <fstream>
using namespace graphic;
using namespace std;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew gr);
	return 0;
}
/*****************************************************************/
#define N 4

#define V f[0]
#define m f[1]
#define n f[2]
#define h f[3]

double f[N];

double C = 1; // muF/cm^2

double g_K = 35; // mS/cm^2
double g_Na = 40; // mS/cm^2
double g_L = 0.3; // mS/cm^2

double E_K = -77; // mV
double E_Na = 55; // mV
double E_L = -65; // mV

int RandomI(int min, int max)
{
    return ((double)rand() / (RAND_MAX - 1)) * (max - min) + min;
}

double RandomD(double min, double max)
{
    return ((double)rand() / RAND_MAX) * (max - min) + min;
}

double alpha_n(double f[N])
{
    return 0.02 * (V - 25) / (1 - exp(-(V - 25) / 9));
}

double beta_n(double f[N])
{
    return -0.002 * (V - 25) / (1 - exp((V - 25) / 9));
}

double alpha_m(double f[N])
{
    return 0.182 * (V + 35) / (1 - exp(-(V + 35) / 9));
}

double beta_m(double f[N])
{
    return -0.124 * (V + 35) / (1 - exp((V + 35) / 9));
}

double alpha_h(double f[N])
{
    return 0.25 * exp(-(V + 90) / 12);
}

double beta_h(double f[N])
{
    return 0.25 * exp((V + 62) / 6) / exp((V + 90) / 12);
}

double HodgkinHuxley(int i, double f[N],double I)
{
    switch (i)
    {
    case 0:
        return 1000 * ((g_Na * pow(m, 3) * h * (E_Na - V) + g_K * n * (E_K - V) + g_L * (E_L - V) + I) / C);

    case 1:
        return 1000 * (alpha_m(f) * (1 - m) - beta_m(f) * m);

    case 2:
        return 1000 * (alpha_n(f) * (1 - n) - beta_n(f) * n);

    case 3:
        return 1000 * (alpha_h(f) * (1 - h) - beta_h(f) * h);
    }
    return 0;
}

void RungeKutta(double dt, double f[N], double f_next[N], double I, double& cmax, double& lv, double& T_period, double& lt, double ct)
{
    double k[N][4];

    if (HodgkinHuxley(0, f, I) <= 0 && lv>0 && V > 0) {
        cmax++;
        if (cmax > 1) {
            T_period = ct - lt;
        }
        lt = ct;
    }

    // k1
    for (int i = 0; i < N; i++)
        k[i][0] = HodgkinHuxley(i, f,I) * dt;

    double phi_k1[N];
    for (int i = 0; i < N; i++)
        phi_k1[i] = f[i] + k[i][0] / 2;

    // k2
    for (int i = 0; i < N; i++)
        k[i][1] = HodgkinHuxley(i, phi_k1,I) * dt;

    double phi_k2[N];
    for (int i = 0; i < N; i++)
        phi_k2[i] = f[i] + k[i][1] / 2;

    // k3
    for (int i = 0; i < N; i++)
        k[i][2] = HodgkinHuxley(i, phi_k2,I) * dt;

    double phi_k3[N];
    for (int i = 0; i < N; i++)
        phi_k3[i] = f[i] + k[i][2] / 2;

    // k4
    for (int i = 0; i < N; i++)
        k[i][3] = HodgkinHuxley(i, phi_k3,I) * dt;

    for (int i = 0; i < N; i++)
        f_next[i] = f[i] + (k[i][0] + 2 * k[i][1] + 2 * k[i][2] + k[i][3]) / 6;


    lv = HodgkinHuxley(0, f, I);
}

void CopyArray(double source[N], double target[N])
{
    for (int i = 0; i < N; i++)
        target[i] = source[i];
}
/*****************************************************************/


System::Void graphic::gr::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->chart1->Series[0]->Points->Clear();
    this->chart1->Series[1]->Points->Clear();

    fstream txRES, tx_LV, tx_I_stim;
    I = Convert::ToDouble(textBox3->Text);
    dI = Convert::ToDouble(textBox2->Text);
    Imax = Convert::ToDouble(textBox1->Text);
    tmax = Convert::ToDouble(textBox4->Text);

    tx_I_stim.open("I_stim_omega.txt");
    double dt = 0.00005;

    while (I <= Imax) {
        tx_LV.open("last_values.txt");
        //-58.7085 0.0953 0.000913 0.3662
        tx_LV >> f[0] >> f[1] >> f[2] >> f[3];
        tx_LV.close();

        double t = 0.0;

        double cmax = 0;
        double lv = 0.0;
        double lt = 0.0;
        double T_period = 0.0;
        double period = 0.0;
        while (t <= tmax) {
            double f_next[N];
            RungeKutta(dt, f, f_next, I, cmax, lv, T_period, lt, t);
            CopyArray(f_next, f);
            t += dt;
        }
        T_period += t - lt;
        tx_LV.open("last_values.txt");
        tx_LV << f[0] << " " << f[1] << " " << f[2] << " " << f[3];
        tx_LV.close();

        T_period = T_period / cmax ;
        T_period = 1 / T_period;
        I = round(I * 1000) / 1000;
        period = cmax / 60;
        if (cmax < 2) {
            tx_I_stim << I << "    |    " << cmax << "    |    " << T_period << "    |    " << period << endl;
            this->chart1->Series[0]->Points->AddXY(I, 0.000001);
        }
        else {
            tx_I_stim << I << "    |    " << cmax << "    |    " << T_period << "    |    " << period << endl;
            this->chart1->Series[0]->Points->AddXY(I, T_period);
        }
        I += dI;
    }

    while (I >= 0.0) {
        txRES.open("results.txt");
        tx_LV.open("last_values.txt");
        tx_LV >> f[0] >> f[1] >> f[2] >> f[3];
        tx_LV.close();

        double t = 0.0;
        double dt = 0.00005;

        double cmax = 0;
        double lv = 0.0;
        double lt = 0.0;
        double T_period = 0.0;
        double period = 0.0;

        while (t <= tmax) {
            double f_next[N];
            RungeKutta(dt, f, f_next, I, cmax, lv, T_period, lt, t);
            CopyArray(f_next, f);
            t += dt;
        }
        T_period += t - lt;
        tx_LV.open("last_values.txt");
        tx_LV << f[0] << " " << f[1] << " " << f[2] << " " << f[3];
        tx_LV.close();

        T_period = T_period / cmax;
        T_period = 1 / T_period;
        I = round(I * 1000) / 1000;
        period = cmax / 60;
        if (cmax < 2) {
            tx_I_stim << I << "    |    " << cmax << "    |    " << T_period << "    |    " << period << endl;
            this->chart1->Series[1]->Points->AddXY(I, 0.000001);
        }
        else {
            tx_I_stim << I << "    |    " << cmax << "    |    " << T_period << "    |    " << period << endl;
            this->chart1->Series[1]->Points->AddXY(I, T_period);
        }
        I -= dI;
    }
    tx_I_stim.close();
	return System::Void();
}

System::Void graphic::gr::vtToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->chart1->Series[0]->Points->Clear();
    this->chart1->Series[1]->Points->Clear();
    fstream txRES, tx_LV, tx_I_stim;
    I = Convert::ToDouble(textBox3->Text);
    dI = Convert::ToDouble(textBox2->Text);
    Imax = Convert::ToDouble(textBox1->Text);
    tmax = Convert::ToDouble(textBox4->Text);

    double dt = 0.00005;

    while (I < Imax) {
        tx_LV.open("last_values.txt");
        //-58.7085 0.0953 0.000913 0.3662
        tx_LV >> f[0] >> f[1] >> f[2] >> f[3];
        tx_LV.close();

        double t = 0.0;
        double cmax = 0;
        double lv = 0.0;
        double lt = 0.0;
        double T_period = 0.0;

        while (t <= tmax) {
            double f_next[N];
            RungeKutta(dt, f, f_next, I, cmax, lv, T_period, lt, t);
            CopyArray(f_next, f);
            t += dt;
        }
        I += dI;
        I = round(I * 1000) / 1000;

        tx_LV.open("last_values.txt");
        tx_LV << f[0] << " " << f[1] << " " << f[2] << " " << f[3];
        tx_LV.close();
    }
    double t = 0.0;
    double cmax = 0;
    double lv = 0.0;
    double lt = 0.0;
    double T_period = 0.0;
    while (t <= tmax) {
        double f_next[N];
        RungeKutta(dt, f, f_next, I, cmax, lv, T_period, lt, t);
        CopyArray(f_next, f);
        this->chart1->Series[0]->Points->AddXY(t, V);
        t += dt;
    }
    return System::Void();
}

System::Void graphic::gr::vhToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->chart1->Series[0]->Points->Clear();
    this->chart1->Series[1]->Points->Clear();
    fstream txRES, tx_LV, tx_I_stim;
    I = Convert::ToDouble(textBox3->Text);
    dI = Convert::ToDouble(textBox2->Text);
    Imax = Convert::ToDouble(textBox1->Text);
    tmax = Convert::ToDouble(textBox4->Text);

    double dt = 0.00005;

    while (I < 1.03) {
        tx_LV.open("last_values.txt");
        //-58.7085 0.0953 0.000913 0.3662
        tx_LV >> f[0] >> f[1] >> f[2] >> f[3];
        tx_LV.close();

        double t = 0.0;
        double cmax = 0;
        double lv = 0.0;
        double lt = 0.0;
        double T_period = 0.0;

        while (t <= tmax) {
            double f_next[N];
            RungeKutta(dt, f, f_next, I, cmax, lv, T_period, lt, t);
            CopyArray(f_next, f);
            t += dt;
        }
        I += dI;
        I = round(I * 1000) / 1000;

        tx_LV.open("last_values.txt");
        tx_LV << f[0] << " " << f[1] << " " << f[2] << " " << f[3];
        tx_LV.close();
    }
    I -= dI;
    while (I < Imax) {
        double t = 0.0;
        double cmax = 0;
        double lv = 0.0;
        double lt = 0.0;
        double T_period = 0.0;
        while (t <= tmax) {
            double f_next[N];
            RungeKutta(dt, f, f_next, I, cmax, lv, T_period, lt, t);
            CopyArray(f_next, f);
            
            t += dt;
        }
        //this->chart1->Series[0]->Points->AddXY(h, V);
        I += 0.0001;
    }
    double t = 0.0;
    double cmax = 0;
    double lv = 0.0;
    double lt = 0.0;
    double T_period = 0.0;
    while (t <= tmax) {
        double f_next[N];
        RungeKutta(dt, f, f_next, I, cmax, lv, T_period, lt, t);
        CopyArray(f_next, f);
        this->chart1->Series[0]->Points->AddXY(h, V);
        t += dt;
    }
    

    return System::Void();
}

System::Void graphic::gr::vnToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->chart1->Series[0]->Points->Clear();
    this->chart1->Series[1]->Points->Clear();
    fstream txRES, tx_LV, tx_I_stim;
    I = Convert::ToDouble(textBox3->Text);
    dI = Convert::ToDouble(textBox2->Text);
    Imax = Convert::ToDouble(textBox1->Text);
    tmax = Convert::ToDouble(textBox4->Text);

    double dt = 0.00005;

    while (I < 1.03) {
        tx_LV.open("last_values.txt");
        //-58.7085 0.0953 0.000913 0.3662
        tx_LV >> f[0] >> f[1] >> f[2] >> f[3];
        tx_LV.close();

        double t = 0.0;
        double cmax = 0;
        double lv = 0.0;
        double lt = 0.0;
        double T_period = 0.0;

        while (t <= tmax) {
            double f_next[N];
            RungeKutta(dt, f, f_next, I, cmax, lv, T_period, lt, t);
            CopyArray(f_next, f);
            t += dt;
        }
        I += dI;
        I = round(I * 1000) / 1000;

        tx_LV.open("last_values.txt");
        tx_LV << f[0] << " " << f[1] << " " << f[2] << " " << f[3];
        tx_LV.close();
    }
    I -= dI;
    while (I < Imax) {
        double t = 0.0;
        double cmax = 0;
        double lv = 0.0;
        double lt = 0.0;
        double T_period = 0.0;
        while (t <= tmax) {
            double f_next[N];
            RungeKutta(dt, f, f_next, I, cmax, lv, T_period, lt, t);
            CopyArray(f_next, f);

            t += dt;
        }
        //this->chart1->Series[0]->Points->AddXY(h, V);
        I += 0.0001;
    }
    double t = 0.0;
    double cmax = 0;
    double lv = 0.0;
    double lt = 0.0;
    double T_period = 0.0;
    while (t <= tmax) {
        double f_next[N];
        RungeKutta(dt, f, f_next, I, cmax, lv, T_period, lt, t);
        CopyArray(f_next, f);
        this->chart1->Series[0]->Points->AddXY(n, V);
        t += dt;
    }

    return System::Void();
}

System::Void graphic::gr::vmToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->chart1->Series[0]->Points->Clear();
    this->chart1->Series[1]->Points->Clear();
    fstream txRES, tx_LV, tx_I_stim;
    I = Convert::ToDouble(textBox3->Text);
    dI = Convert::ToDouble(textBox2->Text);
    Imax = Convert::ToDouble(textBox1->Text);
    tmax = Convert::ToDouble(textBox4->Text);

    double dt = 0.00005;

    while (I < 1.03) {
        tx_LV.open("last_values.txt");
        //-58.7085 0.0953 0.000913 0.3662
        tx_LV >> f[0] >> f[1] >> f[2] >> f[3];
        tx_LV.close();

        double t = 0.0;
        double cmax = 0;
        double lv = 0.0;
        double lt = 0.0;
        double T_period = 0.0;

        while (t <= tmax) {
            double f_next[N];
            RungeKutta(dt, f, f_next, I, cmax, lv, T_period, lt, t);
            CopyArray(f_next, f);
            t += dt;
        }
        I += dI;
        I = round(I * 1000) / 1000;

        tx_LV.open("last_values.txt");
        tx_LV << f[0] << " " << f[1] << " " << f[2] << " " << f[3];
        tx_LV.close();
    }
    I -= dI;
    while (I < Imax) {
        double t = 0.0;
        double cmax = 0;
        double lv = 0.0;
        double lt = 0.0;
        double T_period = 0.0;
        while (t <= tmax) {
            double f_next[N];
            RungeKutta(dt, f, f_next, I, cmax, lv, T_period, lt, t);
            CopyArray(f_next, f);

            t += dt;
        }
        //this->chart1->Series[0]->Points->AddXY(h, V);
        I += 0.0001;
    }
    double t = 0.0;
    double cmax = 0;
    double lv = 0.0;
    double lt = 0.0;
    double T_period = 0.0;
    while (t <= tmax) {
        double f_next[N];
        RungeKutta(dt, f, f_next, I, cmax, lv, T_period, lt, t);
        CopyArray(f_next, f);
        this->chart1->Series[0]->Points->AddXY(m, V);
        t += dt;
    }


    return System::Void();
}

System::Void graphic::gr::hzIappToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->chart1->Series[0]->Points->Clear();
    this->chart1->Series[1]->Points->Clear();

    fstream txRES, tx_LV, tx_I_stim;
    I = Convert::ToDouble(textBox3->Text);
    dI = Convert::ToDouble(textBox2->Text);
    Imax = Convert::ToDouble(textBox1->Text);
    tmax = Convert::ToDouble(textBox4->Text);

    tx_I_stim.open("I_stim_omega.txt");
    double dt = 0.00005;

    while (I <= Imax) {
        tx_LV.open("last_values.txt");
        //-58.7085 0.0953 0.000913 0.3662
        tx_LV >> f[0] >> f[1] >> f[2] >> f[3];
        tx_LV.close();

        double t = 0.0;

        double cmax = 0;
        double lv = 0.0;
        double lt = 0.0;
        double T_period = 0.0;
        double period = 0.0;
        while (t <= tmax) {
            double f_next[N];
            RungeKutta(dt, f, f_next, I, cmax, lv, T_period, lt, t);
            CopyArray(f_next, f);
            t += dt;
        }
        T_period += t - lt;
        tx_LV.open("last_values.txt");
        tx_LV << f[0] << " " << f[1] << " " << f[2] << " " << f[3];
        tx_LV.close();

        T_period = T_period / cmax;
        T_period = 1 / T_period;
        I = round(I * 1000) / 1000;
        period = cmax / 60;
        if (cmax < 2) {
            tx_I_stim << I << "    |    " << cmax << "    |    " << T_period << "    |    " << period << endl;
            this->chart1->Series[0]->Points->AddXY(I, 0.000001);
        }
        else {
            tx_I_stim << I << "    |    " << cmax << "    |    " << T_period << "    |    " << period << endl;
            this->chart1->Series[0]->Points->AddXY(I, T_period);
        }
        I += dI;
    }

    while (I >= 0.0) {
        txRES.open("results.txt");
        tx_LV.open("last_values.txt");
        tx_LV >> f[0] >> f[1] >> f[2] >> f[3];
        tx_LV.close();

        double t = 0.0;
        double dt = 0.00005;

        double cmax = 0;
        double lv = 0.0;
        double lt = 0.0;
        double T_period = 0.0;
        double period = 0.0;

        while (t <= tmax) {
            double f_next[N];
            RungeKutta(dt, f, f_next, I, cmax, lv, T_period, lt, t);
            CopyArray(f_next, f);
            t += dt;
        }
        T_period += t - lt;
        tx_LV.open("last_values.txt");
        tx_LV << f[0] << " " << f[1] << " " << f[2] << " " << f[3];
        tx_LV.close();

        T_period = T_period / cmax;
        T_period = 1 / T_period;
        I = round(I * 1000) / 1000;
        period = cmax / 60;
        if (cmax < 2) {
            tx_I_stim << I << "    |    " << cmax << "    |    " << T_period << "    |    " << period << endl;
            this->chart1->Series[1]->Points->AddXY(I, 0.000001);
        }
        else {
            tx_I_stim << I << "    |    " << cmax << "    |    " << T_period << "    |    " << period << endl;
            this->chart1->Series[1]->Points->AddXY(I, T_period);
        }
        I -= dI;
    }
    tx_I_stim.close();
    return System::Void();
}

System::Void graphic::gr::nutToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->chart1->Series[0]->Points->Clear();
    this->chart1->Series[1]->Points->Clear();
    fstream txRES, tx_LV, tx_I_stim;
    I = Convert::ToDouble(textBox3->Text);
    dI = Convert::ToDouble(textBox2->Text);
    Imax = Convert::ToDouble(textBox1->Text);
    tmax = Convert::ToDouble(textBox4->Text);

    double dt = 0.00005;

    while (I < 1.2) {
        tx_LV.open("last_values.txt");
        //-58.7085 0.0953 0.000913 0.3662
        tx_LV >> f[0] >> f[1] >> f[2] >> f[3];
        tx_LV.close();

        double t = 0.0;
        double cmax = 0;
        double lv = 0.0;
        double lt = 0.0;
        double T_period = 0.0;

        while (t <= tmax) {
            double f_next[N];
            RungeKutta(dt, f, f_next, I, cmax, lv, T_period, lt, t);
            CopyArray(f_next, f);
            t += dt;
        }
        I += dI;
        I = round(I * 1000) / 1000;

        tx_LV.open("last_values.txt");
        tx_LV << f[0] << " " << f[1] << " " << f[2] << " " << f[3];
        tx_LV.close();
    }
    double t = 0.0;
    double cmax = 0;
    double lv = 0.0;
    double lt = 0.0;
    double T_period = 0.0;
    double period = 0.0;
    while (t <= tmax) {
        double f_next[N];
        RungeKutta(dt, f, f_next, I, cmax, lv, T_period, lt, t);

        CopyArray(f_next, f);
        if (T_period != 0) {
            period = 1 / T_period;
        }
        if (T_period == 0.0) {
            this->chart1->Series[0]->Points->AddXY(t, 0.000001);
        }
        else {
            this->chart1->Series[0]->Points->AddXY(t, period);
        }
        t += dt;
    }


    return System::Void();
}
