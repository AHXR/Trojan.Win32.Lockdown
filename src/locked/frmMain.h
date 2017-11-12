#pragma once

namespace AHXRShutdownLocked {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for frmMain
	/// </summary>
	public ref class frmMain : public System::Windows::Forms::Form
	{
	public:
		frmMain(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmMain()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Label^  lblMessage;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Label^  lblTitle;
	private: System::Windows::Forms::ProgressBar^  pgBar;
	private: System::Windows::Forms::Timer^  tmerUpdate;

	private: System::ComponentModel::IContainer^  components;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(frmMain::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->lblTitle = (gcnew System::Windows::Forms::Label());
			this->lblMessage = (gcnew System::Windows::Forms::Label());
			this->pgBar = (gcnew System::Windows::Forms::ProgressBar());
			this->tmerUpdate = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel1->AutoSize = true;
			this->panel1->BackColor = System::Drawing::Color::Red;
			this->panel1->Controls->Add(this->pictureBox1);
			this->panel1->Controls->Add(this->lblTitle);
			this->panel1->Location = System::Drawing::Point(-17, -17);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1226, 133);
			this->panel1->TabIndex = 0;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(40, 31);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(97, 78);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 3;
			this->pictureBox1->TabStop = false;
			// 
			// lblTitle
			// 
			this->lblTitle->AutoSize = true;
			this->lblTitle->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 48, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTitle->ForeColor = System::Drawing::Color::White;
			this->lblTitle->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->lblTitle->Location = System::Drawing::Point(143, 31);
			this->lblTitle->Name = L"lblTitle";
			this->lblTitle->Size = System::Drawing::Size(932, 81);
			this->lblTitle->TabIndex = 2;
			this->lblTitle->Text = L"Shutdown 2017 - System Scan";
			// 
			// lblMessage
			// 
			this->lblMessage->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lblMessage->AutoSize = true;
			this->lblMessage->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblMessage->ForeColor = System::Drawing::Color::White;
			this->lblMessage->Location = System::Drawing::Point(12, 131);
			this->lblMessage->Name = L"lblMessage";
			this->lblMessage->Size = System::Drawing::Size(1586, 366);
			this->lblMessage->TabIndex = 1;
			this->lblMessage->Text = resources->GetString(L"lblMessage.Text");
			this->lblMessage->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblMessage->Click += gcnew System::EventHandler(this, &frmMain::lblMessage_Click);
			// 
			// pgBar
			// 
			this->pgBar->Location = System::Drawing::Point(12, 529);
			this->pgBar->Name = L"pgBar";
			this->pgBar->Size = System::Drawing::Size(768, 76);
			this->pgBar->TabIndex = 2;
			// 
			// tmerUpdate
			// 
			this->tmerUpdate->Enabled = true;
			this->tmerUpdate->Interval = 1000;
			this->tmerUpdate->Tick += gcnew System::EventHandler(this, &frmMain::tmerUpdate_Tick);
			// 
			// frmMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(1203, 617);
			this->Controls->Add(this->pgBar);
			this->Controls->Add(this->lblMessage);
			this->Controls->Add(this->panel1);
			this->ForeColor = System::Drawing::SystemColors::ControlText;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"frmMain";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Shutdown 2017 - Scan";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &frmMain::frmMain_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void frmMain_Load(System::Object^  sender, System::EventArgs^  e) {
		this->lblMessage->Location = System::Drawing::Point(this->Width / 2 - this->lblMessage->Width / 2, this->Height / 2 - this->lblMessage->Height / 2);
		this->pgBar->Location = System::Drawing::Point(this->Width / 2 - this->pgBar->Width / 2, this->Height / 2 - this->pgBar->Height / 2 + 250);
		
		START_FORM_TOP_THREAD();
	}
	private: System::Void tmerUpdate_Tick(System::Object^  sender, System::EventArgs^  e) {
		this->pgBar->Value = this->pgBar->Value + 1;

		if (this->pgBar->Value >= 100)
			FORM_SCAN_STATUS = true;
	
	}
private: System::Void lblMessage_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}
