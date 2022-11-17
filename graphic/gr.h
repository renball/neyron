#pragma once

namespace graphic {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ gr
	/// </summary>
	public ref class gr : public System::Windows::Forms::Form
	{
	public:
		gr(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~gr()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;

	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ выбор√рафикаToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ vtToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ vhToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ vnToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ vmToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ hzIappToolStripMenuItem;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::ToolStripMenuItem^ nutToolStripMenuItem;





	protected:


	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->выбор√рафикаToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->vtToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->vhToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->vnToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->vmToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->hzIappToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->nutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(1338, 729);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(180, 71);
			this->button1->TabIndex = 0;
			this->button1->Text = L"START";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &gr::button1_Click);
			// 
			// chart1
			// 
			chartArea1->AxisX->IntervalAutoMode = System::Windows::Forms::DataVisualization::Charting::IntervalAutoMode::VariableCount;
			chartArea1->AxisX->IsStartedFromZero = false;
			chartArea1->AxisX->MajorGrid->Interval = 0;
			chartArea1->AxisX->MajorGrid->IntervalOffset = 0;
			chartArea1->AxisX->MajorTickMark->Interval = 0;
			chartArea1->AxisX->MajorTickMark->IntervalOffset = 0;
			chartArea1->AxisX->MaximumAutoSize = 100;
			chartArea1->AxisX->MinorGrid->Enabled = true;
			chartArea1->AxisX->MinorGrid->LineColor = System::Drawing::Color::DarkGray;
			chartArea1->AxisX->MinorGrid->LineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Dash;
			chartArea1->AxisX->MinorTickMark->IntervalOffsetType = System::Windows::Forms::DataVisualization::Charting::DateTimeIntervalType::Number;
			chartArea1->AxisX->MinorTickMark->IntervalType = System::Windows::Forms::DataVisualization::Charting::DateTimeIntervalType::Number;
			chartArea1->AxisX->ScaleBreakStyle->LineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Dash;
			chartArea1->AxisX->ScaleView->MinSizeType = System::Windows::Forms::DataVisualization::Charting::DateTimeIntervalType::Number;
			chartArea1->AxisX->ScaleView->SizeType = System::Windows::Forms::DataVisualization::Charting::DateTimeIntervalType::Number;
			chartArea1->AxisX->ScaleView->SmallScrollMinSizeType = System::Windows::Forms::DataVisualization::Charting::DateTimeIntervalType::Number;
			chartArea1->AxisX->ScaleView->SmallScrollSizeType = System::Windows::Forms::DataVisualization::Charting::DateTimeIntervalType::Number;
			chartArea1->AxisX->ScrollBar->ButtonColor = System::Drawing::Color::Gray;
			chartArea1->AxisX2->MajorGrid->Enabled = false;
			chartArea1->AxisX2->MajorGrid->LineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Dot;
			chartArea1->AxisX2->MajorTickMark->Enabled = false;
			chartArea1->AxisY->IsStartedFromZero = false;
			chartArea1->AxisY->MinorGrid->LineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Dot;
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->LegendStyle = System::Windows::Forms::DataVisualization::Charting::LegendStyle::Column;
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(12, 32);
			this->chart1->Name = L"chart1";
			this->chart1->Palette = System::Windows::Forms::DataVisualization::Charting::ChartColorPalette::None;
			series1->BorderWidth = 2;
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series1->Color = System::Drawing::Color::Red;
			series1->Legend = L"Legend1";
			series1->MarkerBorderColor = System::Drawing::Color::Maroon;
			series1->MarkerBorderWidth = 4;
			series1->MarkerSize = 1;
			series1->Name = L"ы";
			series1->SmartLabelStyle->CalloutLineColor = System::Drawing::Color::Red;
			series1->SmartLabelStyle->Enabled = false;
			series2->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			series2->BorderWidth = 2;
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series2->Legend = L"Legend1";
			series2->Name = L"ы2";
			this->chart1->Series->Add(series1);
			this->chart1->Series->Add(series2);
			this->chart1->Size = System::Drawing::Size(1506, 677);
			this->chart1->TabIndex = 2;
			this->chart1->Text = L"chart1";
			this->chart1->UseWaitCursor = true;
			this->chart1->Click += gcnew System::EventHandler(this, &gr::chart1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(1181, 740);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(151, 49);
			this->textBox1->TabIndex = 3;
			this->textBox1->Text = L"0,0";
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &gr::textBox1_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Mongolian Baiti", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(1009, 746);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(166, 40);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Iapp max:";
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->выбор√рафикаToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1530, 29);
			this->menuStrip1->TabIndex = 7;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// выбор√рафикаToolStripMenuItem
			// 
			this->выбор√рафикаToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->vtToolStripMenuItem,
					this->vhToolStripMenuItem, this->vnToolStripMenuItem, this->vmToolStripMenuItem, this->hzIappToolStripMenuItem, this->nutToolStripMenuItem
			});
			this->выбор√рафикаToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->выбор√рафикаToolStripMenuItem->Name = L"выбор√рафикаToolStripMenuItem";
			this->выбор√рафикаToolStripMenuItem->Size = System::Drawing::Size(132, 25);
			this->выбор√рафикаToolStripMenuItem->Text = L"¬ыбор графика";
			// 
			// vtToolStripMenuItem
			// 
			this->vtToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->vtToolStripMenuItem->Name = L"vtToolStripMenuItem";
			this->vtToolStripMenuItem->Size = System::Drawing::Size(180, 26);
			this->vtToolStripMenuItem->Text = L"V(t)";
			this->vtToolStripMenuItem->Click += gcnew System::EventHandler(this, &gr::vtToolStripMenuItem_Click);
			// 
			// vhToolStripMenuItem
			// 
			this->vhToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->vhToolStripMenuItem->Name = L"vhToolStripMenuItem";
			this->vhToolStripMenuItem->Size = System::Drawing::Size(180, 26);
			this->vhToolStripMenuItem->Text = L"V(h)";
			this->vhToolStripMenuItem->Click += gcnew System::EventHandler(this, &gr::vhToolStripMenuItem_Click);
			// 
			// vnToolStripMenuItem
			// 
			this->vnToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->vnToolStripMenuItem->Name = L"vnToolStripMenuItem";
			this->vnToolStripMenuItem->Size = System::Drawing::Size(180, 26);
			this->vnToolStripMenuItem->Text = L"V(n)";
			this->vnToolStripMenuItem->Click += gcnew System::EventHandler(this, &gr::vnToolStripMenuItem_Click);
			// 
			// vmToolStripMenuItem
			// 
			this->vmToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->vmToolStripMenuItem->Name = L"vmToolStripMenuItem";
			this->vmToolStripMenuItem->Size = System::Drawing::Size(180, 26);
			this->vmToolStripMenuItem->Text = L"V(m)";
			this->vmToolStripMenuItem->Click += gcnew System::EventHandler(this, &gr::vmToolStripMenuItem_Click);
			// 
			// hzIappToolStripMenuItem
			// 
			this->hzIappToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->hzIappToolStripMenuItem->Name = L"hzIappToolStripMenuItem";
			this->hzIappToolStripMenuItem->Size = System::Drawing::Size(180, 26);
			this->hzIappToolStripMenuItem->Text = L"Hz(Iapp)";
			this->hzIappToolStripMenuItem->Click += gcnew System::EventHandler(this, &gr::hzIappToolStripMenuItem_Click);
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox2->Location = System::Drawing::Point(843, 740);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(160, 49);
			this->textBox2->TabIndex = 8;
			this->textBox2->Text = L"0,01";
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &gr::textBox2_TextChanged);
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox3->Location = System::Drawing::Point(555, 743);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(157, 49);
			this->textBox3->TabIndex = 9;
			this->textBox3->Text = L"0,0";
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &gr::textBox3_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Mongolian Baiti", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(718, 746);
			this->label2->Name = L"label2";
			this->label2->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->label2->Size = System::Drawing::Size(119, 40);
			this->label2->TabIndex = 10;
			this->label2->Text = L"delta I:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Mongolian Baiti", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(389, 749);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(160, 40);
			this->label3->TabIndex = 11;
			this->label3->Text = L"Iapp min:";
			// 
			// textBox4
			// 
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox4->Location = System::Drawing::Point(250, 743);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(133, 49);
			this->textBox4->TabIndex = 12;
			this->textBox4->Text = L"60,0";
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &gr::textBox4_TextChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Mongolian Baiti", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(143, 749);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(101, 40);
			this->label4->TabIndex = 13;
			this->label4->Text = L"tmax:";
			// 
			// nutToolStripMenuItem
			// 
			this->nutToolStripMenuItem->Name = L"nutToolStripMenuItem";
			this->nutToolStripMenuItem->Size = System::Drawing::Size(180, 26);
			this->nutToolStripMenuItem->Text = L"nu(t)";
			this->nutToolStripMenuItem->Click += gcnew System::EventHandler(this, &gr::nutToolStripMenuItem_Click);
			// 
			// gr
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1530, 812);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"gr";
			this->Text = L"gr";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: float tmax,I,dI,Imax;

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void chart1_Click(System::Object^ sender, System::EventArgs^ e) {
		chart1->SaveImage("graphic.png", System::Drawing::Imaging::ImageFormat::Png);
	}

	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {}
	
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {}
	
	private: System::Void vtToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void vhToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void vnToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void vmToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void hzIappToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nutToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
};
}
