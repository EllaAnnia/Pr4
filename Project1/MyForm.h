#pragma once
#include <iostream>
#include <sstream>
#include <iomanip>
#include <msclr/marshal_cppstd.h>
#include <cmath>
namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label1;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Aquamarine;
			this->button1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->ForeColor = System::Drawing::Color::DarkCyan;
			this->button1->Location = System::Drawing::Point(191, 323);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(333, 73);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Розв\'язати";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::Aquamarine;
			this->textBox1->Location = System::Drawing::Point(191, 91);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(333, 224);
			this->textBox1->TabIndex = 1;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(138, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(442, 83);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 2;
			this->pictureBox1->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::Color::Aquamarine;
			this->label1->Location = System::Drawing::Point(12, 399);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(230, 72);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Виконала:\r\nстудентка групи \r\n4М\r\nЛогвіненко Гання Олександрівна ";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::LightSeaGreen;
			this->ClientSize = System::Drawing::Size(743, 488);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		double Function(double x, double y) {
			return x + cos(y / 2.25);
		}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		double x0 = 1.4;       // начальное значение x
		double y0 = 2.2;       // начальное значение y
		double h = 0.1;        // шаг
		double xMax = 2.4;     // конечное значение x

		// Очистка textBox перед выводом
		textBox1->Clear();

		// Ввод начальных условий
		std::ostringstream oss_initial;
		oss_initial << "x0 = " << x0 << "; y0 = " << y0 << "\n";
		System::String^ richText = msclr::interop::marshal_as<System::String^>(oss_initial.str());
		textBox1->AppendText(richText);

		// Инициализация переменных для метода Эйлера
		double x = x0;
		double y = y0;

		// Цикл метода Эйлера
		while (x <= xMax) {
			y += h * Function(x, y); // Вычисление y по методу Эйлера
			x += h;                  // Шаг по x

			// Ввод текущих значений x и y
			std::ostringstream oss_step;
			oss_step << "x=" << std::fixed << std::setprecision(2) << x
				<< "; y=" << std::setprecision(4) << y << "\n";
			System::String^ stepText = msclr::interop::marshal_as<System::String^>(oss_step.str());
			textBox1->AppendText(stepText);
		}
	}
	};
}
