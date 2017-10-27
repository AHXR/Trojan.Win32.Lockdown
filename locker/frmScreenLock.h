#pragma once
#include "debug.h"

namespace AHXRLocker {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for frmScreenLock
	/// </summary>
	public ref class frmScreenLock : public System::Windows::Forms::Form
	{
	public:
		frmScreenLock(void)
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
		~frmScreenLock()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  txtPassword;
	protected:
	private: System::Windows::Forms::Button^  btnUnlock;
	private: System::Windows::Forms::Label^  lblMessage;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->txtPassword = (gcnew System::Windows::Forms::TextBox());
			this->btnUnlock = (gcnew System::Windows::Forms::Button());
			this->lblMessage = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// txtPassword
			// 
			this->txtPassword->Location = System::Drawing::Point(12, 12);
			this->txtPassword->Name = L"txtPassword";
			this->txtPassword->Size = System::Drawing::Size(128, 20);
			this->txtPassword->TabIndex = 0;
			this->txtPassword->UseSystemPasswordChar = true;
			// 
			// btnUnlock
			// 
			this->btnUnlock->Location = System::Drawing::Point(158, 10);
			this->btnUnlock->Name = L"btnUnlock";
			this->btnUnlock->Size = System::Drawing::Size(73, 23);
			this->btnUnlock->TabIndex = 1;
			this->btnUnlock->Text = L"Unlock";
			this->btnUnlock->UseVisualStyleBackColor = true;
			this->btnUnlock->Click += gcnew System::EventHandler(this, &frmScreenLock::btnUnlock_Click);
			// 
			// lblMessage
			// 
			this->lblMessage->AutoSize = true;
			this->lblMessage->Font = (gcnew System::Drawing::Font(L"Times New Roman", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblMessage->ForeColor = System::Drawing::Color::White;
			this->lblMessage->Location = System::Drawing::Point(95, 124);
			this->lblMessage->Name = L"lblMessage";
			this->lblMessage->Size = System::Drawing::Size(0, 36);
			this->lblMessage->TabIndex = 2;
			// 
			// frmScreenLock
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(292, 272);
			this->Controls->Add(this->lblMessage);
			this->Controls->Add(this->btnUnlock);
			this->Controls->Add(this->txtPassword);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"frmScreenLock";
			this->Text = L"frmScreenLock";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &frmScreenLock::frmScreenLock_FormClosing);
			this->Load += gcnew System::EventHandler(this, &frmScreenLock::frmScreenLock_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnUnlock_Click(System::Object^  sender, System::EventArgs^  e) {
#ifdef EMERGENCY_MODE
		if (this->txtPassword->Text == "hi") {
			exit(1);
		}
#endif

		comparePasswords(this->txtPassword->Text);

		/* 
			The application closes if the password is correct.
			Therefore in any other case, a notification will show up.
		*/
	//	MessageBox::Show("Incorrect Password");
		this->txtPassword->Text = "";
	}
	private: System::Void frmScreenLock_Load(System::Object^  sender, System::EventArgs^  e) {
#ifdef MINIMIZE_WINDOWS
		minimizeAllWindows();
		this->Show();
#endif

		this->lblMessage->Text = getMessage();
		this->lblMessage->Location = System::Drawing::Point(this->Width / 2 - this->lblMessage->Width / 2, this->Height / 2 - this->lblMessage->Height / 2);
	}
	private: System::Void frmScreenLock_Leave(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void frmScreenLock_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
#ifndef DEBUG_MODE
		e->Cancel = true;
#endif
	restoreWindows();
}
};
}
