#ifndef NEWDIALOG_H
#define NEWDIALOG_H

//(*Headers(NewDialog)
#include <wx/choice.h>
#include <wx/dialog.h>
#include <wx/combobox.h>
//*)

class NewDialog: public wxDialog
{
	public:

		NewDialog(wxWindow* parent,wxWindowID id=wxID_ANY);
		virtual ~NewDialog();

		//(*Declarations(NewDialog)
		wxComboBox* ComboBox1;
		wxChoice* Choice1;
		//*)

	protected:

		//(*Identifiers(NewDialog)
		static const long ID_CHOICE1;
		static const long ID_COMBOBOX1;
		//*)

	private:

		//(*Handlers(NewDialog)
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
