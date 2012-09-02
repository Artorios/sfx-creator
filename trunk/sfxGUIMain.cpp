#include "sfxGUIMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(sfxGUIDialog)
#include <wx/artprov.h>
#include <wx/bitmap.h>
#include <wx/settings.h>
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/image.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(sfxGUIDialog)
const long sfxGUIDialog::ID_STATICTEXT1 = wxNewId();
const long sfxGUIDialog::ID_TEXTCTRL1 = wxNewId();
const long sfxGUIDialog::ID_BITMAPBUTTON1 = wxNewId();
const long sfxGUIDialog::ID_BITMAPBUTTON2 = wxNewId();
const long sfxGUIDialog::ID_STATICTEXT4 = wxNewId();
const long sfxGUIDialog::ID_TEXTCTRL2 = wxNewId();
const long sfxGUIDialog::ID_CHOICE2 = wxNewId();
const long sfxGUIDialog::ID_STATICTEXT2 = wxNewId();
const long sfxGUIDialog::ID_CHOICE1 = wxNewId();
const long sfxGUIDialog::ID_STATICTEXT3 = wxNewId();
const long sfxGUIDialog::ID_COMBOBOX1 = wxNewId();
const long sfxGUIDialog::ID_CHECKBOX1 = wxNewId();
const long sfxGUIDialog::ID_BITMAPBUTTON_TITLE = wxNewId();
const long sfxGUIDialog::ID_BITMAPBUTTON_BEGINPROMPT = wxNewId();
const long sfxGUIDialog::ID_BITMAPBUTTON_DIRECTORY = wxNewId();
const long sfxGUIDialog::ID_BITMAPBUTTON_EXECUTEFILE = wxNewId();
const long sfxGUIDialog::ID_HYPERLINKCTRL1 = wxNewId();
const long sfxGUIDialog::ID_STATICTEXT6 = wxNewId();
const long sfxGUIDialog::ID_TEXTCTRL3 = wxNewId();
const long sfxGUIDialog::ID_STATICTEXT7 = wxNewId();
const long sfxGUIDialog::ID_PANEL2 = wxNewId();
const long sfxGUIDialog::ID_BUTTON1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(sfxGUIDialog,wxDialog)
    //(*EventTable(sfxGUIDialog)
    //*)
END_EVENT_TABLE()

sfxGUIDialog::sfxGUIDialog(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(sfxGUIDialog)
    wxStaticBoxSizer* StaticBoxSizerAdvanced;
    wxFlexGridSizer* FlexGridSizer4;
    wxFlexGridSizer* FlexGridSizer3;
    wxFlexGridSizer* FlexGridSizer5;
    wxFlexGridSizer* FlexGridSizer2;
    wxFlexGridSizer* FlexGridSizer7;
    wxFlexGridSizer* FlexGridSizer6;
    wxFlexGridSizer* FlexGridSizer1;

    Create(parent, wxID_ANY, _("7z SFX Creator"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxMINIMIZE_BOX, _T("wxID_ANY"));
    FlexGridSizer1 = new wxFlexGridSizer(0, 1, 0, 0);
    FlexGridSizer1->AddGrowableCol(1);
    FlexGridSizer2 = new wxFlexGridSizer(0, 2, 0, 0);
    FlexGridSizer2->AddGrowableCol(1);
    StaticTextSource = new wxStaticText(this, ID_STATICTEXT1, _("Source:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    FlexGridSizer2->Add(StaticTextSource, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer3 = new wxFlexGridSizer(0, 3, 0, 0);
    FlexGridSizer3->AddGrowableCol(0);
    TextCtrlSource = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    TextCtrlSource->SetMinSize(wxSize(400,-1));
    TextCtrlSource->Disable();
    FlexGridSizer3->Add(TextCtrlSource, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButtonSelectFile = new wxBitmapButton(this, ID_BITMAPBUTTON1, wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_NEW")),wxART_BUTTON), wxDefaultPosition, wxSize(24,24), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON1"));
    BitmapButtonSelectFile->SetDefault();
    BitmapButtonSelectFile->SetToolTip(_("Select Source File..."));
    FlexGridSizer3->Add(BitmapButtonSelectFile, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButtonSelectDirectory = new wxBitmapButton(this, ID_BITMAPBUTTON2, wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_FILE_OPEN")),wxART_BUTTON), wxDefaultPosition, wxSize(24,24), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON2"));
    BitmapButtonSelectDirectory->SetDefault();
    BitmapButtonSelectDirectory->SetToolTip(_("Select Source Directory..."));
    FlexGridSizer3->Add(BitmapButtonSelectDirectory, 1, wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer2->Add(FlexGridSizer3, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticTextTarget = new wxStaticText(this, ID_STATICTEXT4, _("Target:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    FlexGridSizer2->Add(StaticTextTarget, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer4 = new wxFlexGridSizer(0, 2, 0, 0);
    FlexGridSizer4->AddGrowableCol(0);
    TextCtrlTarget = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    FlexGridSizer4->Add(TextCtrlTarget, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    ChoiceCompression = new wxChoice(this, ID_CHOICE2, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE2"));
    ChoiceCompression->Append(_("Store"));
    ChoiceCompression->Append(_("Fastest"));
    ChoiceCompression->Append(_("Fast"));
    ChoiceCompression->SetSelection( ChoiceCompression->Append(_("Normal")) );
    ChoiceCompression->Append(_("Maximum"));
    ChoiceCompression->Append(_("Ultra"));
    ChoiceCompression->SetToolTip(_("Compression Method"));
    FlexGridSizer4->Add(ChoiceCompression, 1, wxTOP|wxBOTTOM|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer2->Add(FlexGridSizer4, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticTextType = new wxStaticText(this, ID_STATICTEXT2, _("Type:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    FlexGridSizer2->Add(StaticTextType, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer5 = new wxFlexGridSizer(0, 4, 0, 0);
    FlexGridSizer5->AddGrowableCol(0);
    FlexGridSizer5->AddGrowableCol(2);
    ChoiceType = new wxChoice(this, ID_CHOICE1, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
    ChoiceType->SetSelection( ChoiceType->Append(_("Self Extracting Installer")) );
    ChoiceType->Append(_("Self Extracting Archive"));
    ChoiceType->SetHelpText(_("SFX Archive:\n + extract files to a directory choosen by the user\n + usage: distribute compressed data files\n\nSFX Installer:\n + extract files to a temporary directory\n + execute a specific file after extraction\n + delete temporary files after completion\n + usage: distribute compressed applications"));
    FlexGridSizer5->Add(ChoiceType, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticTextExecute = new wxStaticText(this, ID_STATICTEXT3, _("Execute File:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    FlexGridSizer5->Add(StaticTextExecute, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    ComboBoxExecute = new wxComboBox(this, ID_COMBOBOX1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX1"));
    ComboBoxExecute->SetHelpText(_("Select a file that will be executed (Installer only)\n+ system files (i.e. notepad.exe) can be used\n+ commandline parameters can be appended after file name\n"));
    FlexGridSizer5->Add(ComboBoxExecute, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    CheckBoxAdvanced = new wxCheckBox(this, ID_CHECKBOX1, _("Advanced"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
    CheckBoxAdvanced->SetValue(false);
    CheckBoxAdvanced->SetToolTip(_("Enable Advanced Mode"));
    FlexGridSizer5->Add(CheckBoxAdvanced, 1, wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer2->Add(FlexGridSizer5, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer2->Add(-1,-1,1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    PanelAdvanced = new wxPanel(this, ID_PANEL2, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    PanelAdvanced->Hide();
    StaticBoxSizerAdvanced = new wxStaticBoxSizer(wxVERTICAL, PanelAdvanced, _("Advanced SFX Installer Configuration:"));
    FlexGridSizer7 = new wxFlexGridSizer(0, 0, 0, 0);
    BitmapButtonMenuTitle = new wxBitmapButton(PanelAdvanced, ID_BITMAPBUTTON_TITLE, wxNullBitmap, wxDefaultPosition, wxSize(24,24), 0, wxDefaultValidator, _T("ID_BITMAPBUTTON_TITLE"));
    BitmapButtonMenuTitle->SetDefault();
    BitmapButtonMenuTitle->SetToolTip(_("Insert Title Command"));
    resourceMemoryStream = new wxMemoryInputStream(RESOURCES::TITLE_PNG.data, RESOURCES::TITLE_PNG.length);
    BitmapButtonMenuTitle->SetBitmapLabel(wxBitmap(wxImage(*resourceMemoryStream, wxBITMAP_TYPE_PNG)));
    wxDELETE(resourceMemoryStream);
    resourceMemoryStream = NULL;
    resourceMemoryStream = new wxMemoryInputStream(RESOURCES::TITLE_DISABLED_PNG.data, RESOURCES::TITLE_DISABLED_PNG.length);
    BitmapButtonMenuTitle->SetBitmapDisabled(wxBitmap(wxImage(*resourceMemoryStream, wxBITMAP_TYPE_PNG)));
    wxDELETE(resourceMemoryStream);
    resourceMemoryStream = NULL;
    FlexGridSizer7->Add(BitmapButtonMenuTitle, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButtonMenuBeginPrompt = new wxBitmapButton(PanelAdvanced, ID_BITMAPBUTTON_BEGINPROMPT, wxNullBitmap, wxDefaultPosition, wxSize(24,24), 0, wxDefaultValidator, _T("ID_BITMAPBUTTON_BEGINPROMPT"));
    BitmapButtonMenuBeginPrompt->SetDefault();
    BitmapButtonMenuBeginPrompt->SetToolTip(_("Insert BeginPrompt Command"));
    resourceMemoryStream = new wxMemoryInputStream(RESOURCES::REPORT_PNG.data, RESOURCES::REPORT_PNG.length);
    BitmapButtonMenuBeginPrompt->SetBitmapLabel(wxBitmap(wxImage(*resourceMemoryStream, wxBITMAP_TYPE_PNG)));
    wxDELETE(resourceMemoryStream);
    resourceMemoryStream = NULL;
    resourceMemoryStream = new wxMemoryInputStream(RESOURCES::REPORT_DISABLED_PNG.data, RESOURCES::REPORT_DISABLED_PNG.length);
    BitmapButtonMenuBeginPrompt->SetBitmapDisabled(wxBitmap(wxImage(*resourceMemoryStream, wxBITMAP_TYPE_PNG)));
    wxDELETE(resourceMemoryStream);
    resourceMemoryStream = NULL;
    FlexGridSizer7->Add(BitmapButtonMenuBeginPrompt, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButtonMenuDirectory = new wxBitmapButton(PanelAdvanced, ID_BITMAPBUTTON_DIRECTORY, wxNullBitmap, wxDefaultPosition, wxSize(24,24), 0, wxDefaultValidator, _T("ID_BITMAPBUTTON_DIRECTORY"));
    BitmapButtonMenuDirectory->SetDefault();
    BitmapButtonMenuDirectory->SetToolTip(_("Insert Directory Command"));
    resourceMemoryStream = new wxMemoryInputStream(RESOURCES::FOLDER_OPEN_PNG.data, RESOURCES::FOLDER_OPEN_PNG.length);
    BitmapButtonMenuDirectory->SetBitmapLabel(wxBitmap(wxImage(*resourceMemoryStream, wxBITMAP_TYPE_PNG)));
    wxDELETE(resourceMemoryStream);
    resourceMemoryStream = NULL;
    resourceMemoryStream = new wxMemoryInputStream(RESOURCES::FOLDER_OPEN_DISABLED_PNG.data, RESOURCES::FOLDER_OPEN_DISABLED_PNG.length);
    BitmapButtonMenuDirectory->SetBitmapDisabled(wxBitmap(wxImage(*resourceMemoryStream, wxBITMAP_TYPE_PNG)));
    wxDELETE(resourceMemoryStream);
    resourceMemoryStream = NULL;
    FlexGridSizer7->Add(BitmapButtonMenuDirectory, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButtonMenuExecuteFile = new wxBitmapButton(PanelAdvanced, ID_BITMAPBUTTON_EXECUTEFILE, wxNullBitmap, wxDefaultPosition, wxSize(24,24), 0, wxDefaultValidator, _T("ID_BITMAPBUTTON_EXECUTEFILE"));
    BitmapButtonMenuExecuteFile->SetDefault();
    BitmapButtonMenuExecuteFile->SetToolTip(_("Insert ExecuteFile Command"));
    resourceMemoryStream = new wxMemoryInputStream(RESOURCES::EXECUTE_FILE_PNG.data, RESOURCES::EXECUTE_FILE_PNG.length);
    BitmapButtonMenuExecuteFile->SetBitmapLabel(wxBitmap(wxImage(*resourceMemoryStream, wxBITMAP_TYPE_PNG)));
    wxDELETE(resourceMemoryStream);
    resourceMemoryStream = NULL;
    resourceMemoryStream = new wxMemoryInputStream(RESOURCES::EXECUTE_FILE_DISABLED_PNG.data, RESOURCES::EXECUTE_FILE_DISABLED_PNG.length);
    BitmapButtonMenuExecuteFile->SetBitmapDisabled(wxBitmap(wxImage(*resourceMemoryStream, wxBITMAP_TYPE_PNG)));
    wxDELETE(resourceMemoryStream);
    resourceMemoryStream = NULL;
    FlexGridSizer7->Add(BitmapButtonMenuExecuteFile, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    HyperlinkCtrlOnlineHelp = new wxHyperlinkCtrl(PanelAdvanced, ID_HYPERLINKCTRL1, _("\?"), _("http://7zsfx.info/en/parameters.html"), wxDefaultPosition, wxDefaultSize, wxHL_CONTEXTMENU|wxHL_ALIGN_CENTRE|wxNO_BORDER, _T("ID_HYPERLINKCTRL1"));
    HyperlinkCtrlOnlineHelp->SetToolTip(_("Open the online documentation for SFX configuration parameters..."));
    FlexGridSizer7->Add(HyperlinkCtrlOnlineHelp, 1, wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizerAdvanced->Add(FlexGridSizer7, 1, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer6 = new wxFlexGridSizer(0, 1, 0, 0);
    FlexGridSizer6->AddGrowableCol(0);
    FlexGridSizer6->AddGrowableRow(1);
    StaticTextConfigHeader = new wxStaticText(PanelAdvanced, ID_STATICTEXT6, _(";!@Install@!UTF-8!"), wxDefaultPosition, wxDefaultSize, wxNO_BORDER, _T("ID_STATICTEXT6"));
    StaticTextConfigHeader->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_GRAYTEXT));
    FlexGridSizer6->Add(StaticTextConfigHeader, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlAdvanced = new wxTextCtrl(PanelAdvanced, ID_TEXTCTRL3, _("ExecuteFile=\"\""), wxDefaultPosition, wxSize(0,100), wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    FlexGridSizer6->Add(TextCtrlAdvanced, 1, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticTextConfigFooter = new wxStaticText(PanelAdvanced, ID_STATICTEXT7, _(";!@InstallEnd@!"), wxDefaultPosition, wxDefaultSize, wxNO_BORDER, _T("ID_STATICTEXT7"));
    StaticTextConfigFooter->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_GRAYTEXT));
    FlexGridSizer6->Add(StaticTextConfigFooter, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizerAdvanced->Add(FlexGridSizer6, 0, wxEXPAND|wxALIGN_LEFT|wxALIGN_TOP, 0);
    PanelAdvanced->SetSizer(StaticBoxSizerAdvanced);
    StaticBoxSizerAdvanced->Fit(PanelAdvanced);
    StaticBoxSizerAdvanced->SetSizeHints(PanelAdvanced);
    FlexGridSizer2->Add(PanelAdvanced, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(FlexGridSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    ButtonCreate = new wxButton(this, ID_BUTTON1, _("Create SFX"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    ButtonCreate->SetFocus();
    wxFont ButtonCreateFont(wxDEFAULT,wxDEFAULT,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    ButtonCreate->SetFont(ButtonCreateFont);
    FlexGridSizer1->Add(ButtonCreate, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(FlexGridSizer1);
    DirDialogSource = new wxDirDialog(this, _("Select directory"), wxEmptyString, wxDD_DEFAULT_STYLE, wxDefaultPosition, wxDefaultSize, _T("wxDirDialog"));
    FileDialogSource = new wxFileDialog(this, _("Select file"), wxEmptyString, wxEmptyString, wxFileSelectorDefaultWildcardStr, wxFD_DEFAULT_STYLE, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
    FlexGridSizer1->Fit(this);
    FlexGridSizer1->SetSizeHints(this);
    Center();

    Connect(ID_BITMAPBUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&sfxGUIDialog::OnBitmapButtonSelectFileClick);
    Connect(ID_BITMAPBUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&sfxGUIDialog::OnBitmapButtonSelectDirectoryClick);
    Connect(ID_CHOICE1,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&sfxGUIDialog::OnChoiceTypeSelect);
    Connect(ID_CHECKBOX1,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&sfxGUIDialog::OnCheckBoxAdvancedClick);
    Connect(ID_BITMAPBUTTON_TITLE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&sfxGUIDialog::OnBitmapButtonMenuClick);
    Connect(ID_BITMAPBUTTON_BEGINPROMPT,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&sfxGUIDialog::OnBitmapButtonMenuClick);
    Connect(ID_BITMAPBUTTON_DIRECTORY,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&sfxGUIDialog::OnBitmapButtonMenuClick);
    Connect(ID_BITMAPBUTTON_EXECUTEFILE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&sfxGUIDialog::OnBitmapButtonMenuClick);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&sfxGUIDialog::OnButtonCreateClick);
    //*)
}

sfxGUIDialog::~sfxGUIDialog()
{
    //(*Destroy(sfxGUIDialog)
    //*)
}

SFX_SOURCE sfxGUIDialog::GetSourceType(wxString path)
{
    // Check if path is a valid directory
    if(wxDirExists(path))
    {
        return SFX_SOURCE_DIRECTORY;
    }
    // Check if path is a valid file
    if(wxFileExists(path))
    {
        return SFX_SOURCE_FILE;
    }

    return SFX_SOURCE_INVALID;
}

void sfxGUIDialog::SetSource(wxString path)
{
    SetCursor(wxCURSOR_WAIT);

    SFX_SOURCE type = GetSourceType(path);

    TextCtrlSource->SetValue(path);
    TextCtrlTarget->Clear();
    ComboBoxExecute->Clear();

    // check if path is a valid directory
    if(type == SFX_SOURCE_DIRECTORY)
    {
        TextCtrlTarget->SetValue(path + wxT(".exe"));
        wxArrayString files;
        wxDir::GetAllFiles(path, &files, wxT("*.*"), wxDIR_FILES); // get all files from initial directory (no sub-directories)
        if(files.GetCount() > 0)
        {
            for(wxUint32 i=0; i<files.GetCount(); i++)
            {
                files[i].Replace(path + wxT("\\"), wxT(""));
                ComboBoxExecute->Append(files[i]);
            }
        }
    }

    // check if path is a valid file
    if(type == SFX_SOURCE_FILE)
    {
        if(path.EndsWith(wxT(".exe")))
        {
            TextCtrlTarget->SetValue(path.BeforeLast('.') + wxT(".sfx.exe"));
        }
        else
        {
            TextCtrlTarget->SetValue(path + wxT(".exe"));
        }
        ComboBoxExecute->Append(path.AfterLast('\\'));
    }

    // check if soure is invalid
    if(type == SFX_SOURCE_INVALID)
    {
        TextCtrlSource->Clear();
    }

    SetCursor(wxCURSOR_DEFAULT);
}

void sfxGUIDialog::OnBitmapButtonSelectFileClick(wxCommandEvent& event)
{
    if(FileDialogSource->ShowModal() == wxID_OK)
    {
        SetSource(FileDialogSource->GetDirectory() + wxT("\\") + FileDialogSource->GetFilename());
    }
}

void sfxGUIDialog::OnBitmapButtonSelectDirectoryClick(wxCommandEvent& event)
{
    if(DirDialogSource->ShowModal() == wxID_OK)
    {
        SetSource(DirDialogSource->GetPath());
    }
}

void sfxGUIDialog::OnChoiceTypeSelect(wxCommandEvent& event)
{
    if(GetSfxType() == SFX_TYPE_INSTALLER)
    {
        if(!CheckBoxAdvanced->GetValue())
        {
            StaticTextExecute->Enable(true);
            ComboBoxExecute->Enable(true);
        }
        else
        {
            StaticTextExecute->Enable(false);
            ComboBoxExecute->Enable(false);
        }
        CheckBoxAdvanced->Enable(true);
        PanelAdvanced->Enable(true);
        BitmapButtonMenuExecuteFile->Enable(true);
    }
    else
    {
        StaticTextExecute->Enable(false);
        ComboBoxExecute->Enable(false);
        CheckBoxAdvanced->Enable(false);
        PanelAdvanced->Enable(false);
        BitmapButtonMenuExecuteFile->Enable(false);
    }
}

void sfxGUIDialog::OnCheckBoxAdvancedClick(wxCommandEvent& event)
{
    if(CheckBoxAdvanced->GetValue())
    {
        PanelAdvanced->Show();
    }
    else
    {
        PanelAdvanced->Hide();
    }

    wxCommandEvent ce;
    OnChoiceTypeSelect(ce);

    Fit();
    //Center();
}

SFX_TYPE sfxGUIDialog::GetSfxType()
{
    if(ChoiceType->GetSelection() > -1)
    {
        if(ChoiceType->GetStringSelection().Contains(wxT("Archive")))
        {
            return SFX_TYPE_ARCHIVE;
        }
        if(ChoiceType->GetStringSelection().Contains(wxT("Installer")))
        {
            return SFX_TYPE_INSTALLER;
        }
    }
    return SFX_TYPE_UNKNOWN;
}

void sfxGUIDialog::OnBitmapButtonMenuClick(wxCommandEvent& event)
{
    wxString content = TextCtrlAdvanced->GetValue();

    if(!content.IsEmpty() && !content.EndsWith(wxT("\n")))
    {
        content += wxT("\n");
    }

    if(event.GetId() == ID_BITMAPBUTTON_DIRECTORY)
    {
        TextCtrlAdvanced->SetValue(content + wxT("Directory=\"%%T\""));
    }
    if(event.GetId() == ID_BITMAPBUTTON_BEGINPROMPT)
    {
        TextCtrlAdvanced->SetValue(content + wxT("BeginPrompt=\"Text\""));
    }
    if(event.GetId() == ID_BITMAPBUTTON_EXECUTEFILE)
    {
        TextCtrlAdvanced->SetValue(content + wxT("ExecuteFile=\"File\""));
    }
    if(event.GetId() == ID_BITMAPBUTTON_TITLE)
    {
        TextCtrlAdvanced->SetValue(content + wxT("Title=\"Title\""));
    }
}

wxString sfxGUIDialog::GetSfxConfiguration()
{
    wxString configuration;
    wxString content;

    if(CheckBoxAdvanced->GetValue())
    {
        content = TextCtrlAdvanced->GetValue();
    }
    else
    {
        content = wxT("ExecuteFile=\"") + ComboBoxExecute->GetValue() + wxT("\"");
    }

    configuration += StaticTextConfigHeader->GetLabel() + wxT("\n");
    configuration += content + wxT("\n");
    configuration += StaticTextConfigFooter->GetLabel();

    return configuration;
}

void sfxGUIDialog::CreateFileSfxModule(wxString path, SFX_TYPE sfxType, wxString sfxConfiguration)
{
    if(wxFileExists(path))
    {
        wxRemoveFile(path);
    }

    wxFileOutputStream *outputStream = new wxFileOutputStream(path);
    wxString appPath = wxStandardPaths::Get().GetExecutablePath().BeforeLast('\\');

    if(sfxType == SFX_TYPE_ARCHIVE)
    {
        outputStream->Write(RESOURCES::_7Z_SFX.data, RESOURCES::_7Z_SFX.length);
    }

    if(sfxType == SFX_TYPE_INSTALLER)
    {
        outputStream->Write(RESOURCES::_7ZS_SFX.data, RESOURCES::_7ZS_SFX.length);
        wxCharBuffer configuration_bytes = sfxConfiguration.ToUTF8();
        outputStream->Write(configuration_bytes, strlen(configuration_bytes.data())); // strlen counts characters until terminating NULL character...
    }

    outputStream->Close();
    wxDELETE(outputStream);
}

wxString sfxGUIDialog::Create7zCommand(wxString source, wxString target, wxInt32 compression, wxString sfx)
{
    wxString command = wxT("7zG.exe a");

    if(compression > -1 && compression < 10)
    {
        command += wxString::Format(wxT(" -mx%i"), compression);
    }

    if(!sfx.IsEmpty())
    {
        command += wxT(" -sfx\"") + sfx + wxT("\"");
    }

    command += wxT(" \"") + target + wxT("\"");
    command += wxT(" \"") + source + wxT("\"");

    return command;
}

void sfxGUIDialog::OnButtonCreateClick(wxCommandEvent& event)
{
    SetCursor(wxCURSOR_WAIT);

    EnableDisableControls(false);

    wxString sourcePath = TextCtrlSource->GetValue();
    wxString targetPath = TextCtrlTarget->GetValue();
    if(!sourcePath.IsEmpty() && !targetPath.IsEmpty() && wxDirExists(targetPath.BeforeLast('\\')))
    {
        wxInt32 compression = wxMax(0, 2*ChoiceCompression->GetSelection()-1);
        wxString sfxPath = wxStandardPaths::Get().GetExecutablePath().BeforeLast('\\') + wxT("\\") + wxT("7zSFX.tmp");
        SFX_TYPE sfxType = GetSfxType();
        wxString sfxConfiguration = GetSfxConfiguration();

        if(sfxType == SFX_TYPE_INSTALLER && GetSourceType(sourcePath) == SFX_SOURCE_DIRECTORY)
        {
            sourcePath += wxT("\\*\"");
        }

        CreateFileSfxModule(sfxPath, sfxType, sfxConfiguration);
        wxExecute(Create7zCommand(sourcePath, targetPath, compression, sfxPath), wxEXEC_SYNC); // EXEC_SYNC to wait for 7zip
        wxRemoveFile(sfxPath);
        Raise(); // focus back to this dialog after 7zip finished
    }

    EnableDisableControls(true);

    SetCursor(wxCURSOR_DEFAULT);
}

void sfxGUIDialog::EnableDisableControls(bool enable)
{
    if(enable)
    {
        BitmapButtonSelectDirectory->Enable(true);
        BitmapButtonSelectFile->Enable(true);
        TextCtrlTarget->Enable(true);
        ChoiceCompression->Enable(true);
        ChoiceType->Enable(true);
        if(GetSfxType() == SFX_TYPE_INSTALLER)
        {
            if(!CheckBoxAdvanced->GetValue())
            {
                ComboBoxExecute->Enable(true);
            }
            CheckBoxAdvanced->Enable(true);
            PanelAdvanced->Enable(true);
        }
        ButtonCreate->Enable(true);
    }
    else
    {
        BitmapButtonSelectDirectory->Enable(false);
        BitmapButtonSelectFile->Enable(false);
        TextCtrlTarget->Enable(false);
        ChoiceCompression->Enable(false);
        ChoiceType->Enable(false);
        ComboBoxExecute->Enable(false);
        CheckBoxAdvanced->Enable(false);
        PanelAdvanced->Enable(false);
        ButtonCreate->Enable(false);
    }
}
