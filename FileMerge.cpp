#include "FileMerge.h"

//(*InternalHeaders(FileMerge)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(FileMerge)
const long FileMerge::ID_LISTBOX1 = wxNewId();
const long FileMerge::ID_TEXTCTRL1 = wxNewId();
const long FileMerge::ID_GAUGE1 = wxNewId();
const long FileMerge::ID_BUTTON1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(FileMerge,wxDialog)
	//(*EventTable(FileMerge)
	//*)
END_EVENT_TABLE()

FileMerge::FileMerge(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(FileMerge)
	wxStaticBoxSizer* StaticBoxSizer2;
	wxFlexGridSizer* FlexGridSizer3;
	wxFlexGridSizer* FlexGridSizer2;
	wxStaticBoxSizer* StaticBoxSizer1;
	wxFlexGridSizer* FlexGridSizer1;

	Create(parent, wxID_ANY, _("File Merge"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	FlexGridSizer1 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer1->AddGrowableCol(0);
	FlexGridSizer1->AddGrowableRow(0);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Input"));
	ListBoxFilesIn = new wxListBox(this, ID_LISTBOX1, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_LISTBOX1"));
	ListBoxFilesIn->SetMinSize(wxSize(-1,160));
	StaticBoxSizer1->Add(ListBoxFilesIn, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(StaticBoxSizer1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Output"));
	FlexGridSizer2 = new wxFlexGridSizer(0, 1, 0, 0);
	TextCtrlFileOut = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	FlexGridSizer2->Add(TextCtrlFileOut, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer3 = new wxFlexGridSizer(0, 2, 0, 0);
	FlexGridSizer3->AddGrowableCol(0);
	GaugeProgress = new wxGauge(this, ID_GAUGE1, 100, wxDefaultPosition, wxSize(420,18), wxGA_SMOOTH, wxDefaultValidator, _T("ID_GAUGE1"));
	FlexGridSizer3->Add(GaugeProgress, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ButtonCancel = new wxButton(this, ID_BUTTON1, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	FlexGridSizer3->Add(ButtonCancel, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer2->Add(FlexGridSizer3, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	StaticBoxSizer2->Add(FlexGridSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	FlexGridSizer1->Add(StaticBoxSizer2, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(FlexGridSizer1);
	FlexGridSizer1->Fit(this);
	FlexGridSizer1->SetSizeHints(this);
	Center();

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&FileMerge::OnButtonCancelClick);
	//*)
}

FileMerge::~FileMerge()
{
	//(*Destroy(FileMerge)
	//*)
}

void FileMerge::AppendFileToStream(wxFileOutputStream *outputStream, wxString inputFile)
{
    if(wxFileExists(inputFile))
    {
        wxFileInputStream *inputStream = new wxFileInputStream(inputFile);
        size_t bytes_read;
        size_t bytes = inputStream->GetSize();

        // if filesize is unknown or greater 2MB read in chunks
        if(bytes <= 0 || bytes > 2097152)
        {
            bytes = 2097152; // 2 MB chunks
        }

        wxByte* buffer = new wxByte[bytes];

        while(!inputStream->Eof())
        {
            wxYield();
            if(abort)
            {
                break;
            }

            inputStream->Read(buffer, bytes);
            bytes_read = inputStream->LastRead();

            GaugeProgress->SetValue((wxInt32)((wxFileOffset)GaugeProgress->GetRange()*inputStream->TellI() / inputStream->GetLength()));

            if(bytes_read > 0)
            {
                outputStream->Write(buffer, bytes_read);
            }
            else
            {
                break; // maybe an error on read
            }
        }

        wxDELETEA(buffer);
        wxDELETE(inputStream);
    }
}

void FileMerge::AddInputFiles(wxArrayString files)
{
    ListBoxFilesIn->Append(files);
}

void FileMerge::SetOutputFile(wxString file)
{
    TextCtrlFileOut->SetValue(file);
}

void FileMerge::MergeFiles()
{
    wxString outputFile = TextCtrlFileOut->GetValue();
    wxString inputFile;

    if(ListBoxFilesIn->GetCount() > 0 && wxDirExists(outputFile.BeforeLast('\\')))
    {
        abort = false;

        wxFileOutputStream *outputStream = new wxFileOutputStream(outputFile);

        for(wxUint32 i=0; i<ListBoxFilesIn->GetCount(); i++)
        {
            wxYield();
            if(abort)
            {
                break;
            }

            inputFile = ListBoxFilesIn->GetString(i);
            ListBoxFilesIn->Select(i);

            if(wxFileExists(inputFile))
            {
                AppendFileToStream(outputStream, inputFile);
            }
        }

        outputStream->Close();
        wxDELETE(outputStream);
        ListBoxFilesIn->Select(-1);
    }
}

void FileMerge::OnButtonCancelClick(wxCommandEvent& event)
{
    abort = true;
}
