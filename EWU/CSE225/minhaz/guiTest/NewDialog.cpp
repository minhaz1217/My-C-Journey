#include "NewDialog.h"

//(*InternalHeaders(NewDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(NewDialog)
const long NewDialog::ID_CHOICE1 = wxNewId();
const long NewDialog::ID_COMBOBOX1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(NewDialog,wxDialog)
	//(*EventTable(NewDialog)
	//*)
END_EVENT_TABLE()

NewDialog::NewDialog(wxWindow* parent,wxWindowID id)
{
	//(*Initialize(NewDialog)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	Choice1 = new wxChoice(this, ID_CHOICE1, wxPoint(112,128), wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
	ComboBox1 = new wxComboBox(this, ID_COMBOBOX1, wxEmptyString, wxPoint(176,232), wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX1"));
	//*)
}

NewDialog::~NewDialog()
{
	//(*Destroy(NewDialog)
	//*)
}

