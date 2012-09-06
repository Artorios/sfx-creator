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
    wxFlexGridSizer* FlexGridSizer6;

    Create(parent, wxID_ANY, _("7z SFX Creator"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxMINIMIZE_BOX, _T("wxID_ANY"));
    GridBagSizerWindow = new wxGridBagSizer(0, 0);
    GridBagSizerWindow->AddGrowableCol(1);
    GridBagSizerWindow->AddGrowableCol(3);
    GridBagSizerWindow->AddGrowableRow(3);
    StaticTextSource = new wxStaticText(this, ID_STATICTEXT1, _("Source:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    GridBagSizerWindow->Add(StaticTextSource, wxGBPosition(0, 0), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlSource = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    TextCtrlSource->SetMinSize(wxSize(488,-1));
    TextCtrlSource->Disable();
    GridBagSizerWindow->Add(TextCtrlSource, wxGBPosition(0, 1), wxGBSpan(1, 4), wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButtonSelectFile = new wxBitmapButton(this, ID_BITMAPBUTTON1, wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_NEW")),wxART_BUTTON), wxDefaultPosition, wxSize(24,24), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON1"));
    BitmapButtonSelectFile->SetDefault();
    BitmapButtonSelectFile->SetToolTip(_("Select Source File..."));
    GridBagSizerWindow->Add(BitmapButtonSelectFile, wxGBPosition(0, 5), wxDefaultSpan, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButtonSelectDirectory = new wxBitmapButton(this, ID_BITMAPBUTTON2, wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_FILE_OPEN")),wxART_BUTTON), wxDefaultPosition, wxSize(24,24), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON2"));
    BitmapButtonSelectDirectory->SetDefault();
    BitmapButtonSelectDirectory->SetToolTip(_("Select Source Directory..."));
    GridBagSizerWindow->Add(BitmapButtonSelectDirectory, wxGBPosition(0, 6), wxDefaultSpan, wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticTextTarget = new wxStaticText(this, ID_STATICTEXT4, _("Target:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    GridBagSizerWindow->Add(StaticTextTarget, wxGBPosition(1, 0), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlTarget = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    TextCtrlTarget->SetMinSize(wxSize(440,-1));
    GridBagSizerWindow->Add(TextCtrlTarget, wxGBPosition(1, 1), wxGBSpan(1, 3), wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    ChoiceCompression = new wxChoice(this, ID_CHOICE2, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE2"));
    ChoiceCompression->Append(_("Store"));
    ChoiceCompression->Append(_("Fastest"));
    ChoiceCompression->Append(_("Fast"));
    ChoiceCompression->SetSelection( ChoiceCompression->Append(_("Normal")) );
    ChoiceCompression->Append(_("Maximum"));
    ChoiceCompression->Append(_("Ultra"));
    ChoiceCompression->SetToolTip(_("Compression Method"));
    GridBagSizerWindow->Add(ChoiceCompression, wxGBPosition(1, 4), wxGBSpan(1, 3), wxTOP|wxBOTTOM|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticTextType = new wxStaticText(this, ID_STATICTEXT2, _("Type:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    GridBagSizerWindow->Add(StaticTextType, wxGBPosition(2, 0), wxDefaultSpan, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    ChoiceType = new wxChoice(this, ID_CHOICE1, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
    ChoiceType->SetSelection( ChoiceType->Append(_("Self Extracting Installer")) );
    ChoiceType->Append(_("Self Extracting Archive"));
    ChoiceType->SetMinSize(wxSize(180,-1));
    ChoiceType->SetHelpText(_("SFX Archive:\n + extract files to a directory choosen by the user\n + usage: distribute compressed data files\n\nSFX Installer:\n + extract files to a temporary directory\n + execute a specific file after extraction\n + delete temporary files after completion\n + usage: distribute compressed applications"));
    GridBagSizerWindow->Add(ChoiceType, wxGBPosition(2, 1), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticTextExecute = new wxStaticText(this, ID_STATICTEXT3, _("Execute File:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    GridBagSizerWindow->Add(StaticTextExecute, wxGBPosition(2, 2), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    ComboBoxExecute = new wxComboBox(this, ID_COMBOBOX1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX1"));
    ComboBoxExecute->SetMinSize(wxSize(180,-1));
    ComboBoxExecute->SetHelpText(_("Select a file that will be executed (Installer only)\n+ system files (i.e. notepad.exe) can be used\n+ commandline parameters can be appended after file name\n"));
    GridBagSizerWindow->Add(ComboBoxExecute, wxGBPosition(2, 3), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    CheckBoxAdvanced = new wxCheckBox(this, ID_CHECKBOX1, _("Advanced Conf"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
    CheckBoxAdvanced->SetValue(false);
    CheckBoxAdvanced->SetToolTip(_("Enable Advanced Mode"));
    GridBagSizerWindow->Add(CheckBoxAdvanced, wxGBPosition(2, 4), wxGBSpan(1, 3), wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    PanelAdvanced = new wxPanel(this, ID_PANEL2, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    PanelAdvanced->Hide();
    StaticBoxSizerAdvanced = new wxStaticBoxSizer(wxVERTICAL, PanelAdvanced, _("Advanced SFX Installer Configuration:"));
    FlexGridSizer6 = new wxFlexGridSizer(0, 1, 0, 0);
    FlexGridSizer6->AddGrowableCol(0);
    FlexGridSizer6->AddGrowableRow(2);
    HyperlinkCtrlOnlineHelp = new wxHyperlinkCtrl(PanelAdvanced, ID_HYPERLINKCTRL1, _("[\?]"), _("http://7zsfx.info/en/parameters.html"), wxDefaultPosition, wxDefaultSize, wxHL_CONTEXTMENU|wxHL_ALIGN_CENTRE|wxNO_BORDER, _T("ID_HYPERLINKCTRL1"));
    HyperlinkCtrlOnlineHelp->SetToolTip(_("Open the online documentation for SFX configuration parameters..."));
    FlexGridSizer6->Add(HyperlinkCtrlOnlineHelp, 1, wxLEFT|wxRIGHT|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    StaticTextConfigHeader = new wxStaticText(PanelAdvanced, ID_STATICTEXT6, _(";!@Install@!UTF-8!"), wxDefaultPosition, wxDefaultSize, wxNO_BORDER, _T("ID_STATICTEXT6"));
    StaticTextConfigHeader->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_GRAYTEXT));
    FlexGridSizer6->Add(StaticTextConfigHeader, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlAdvanced = new wxTextCtrl(PanelAdvanced, ID_TEXTCTRL3, _("ExecuteFile=\"\""), wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    TextCtrlAdvanced->SetMinSize(wxSize(-1,100));
    FlexGridSizer6->Add(TextCtrlAdvanced, 1, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticTextConfigFooter = new wxStaticText(PanelAdvanced, ID_STATICTEXT7, _(";!@InstallEnd@!"), wxDefaultPosition, wxDefaultSize, wxNO_BORDER, _T("ID_STATICTEXT7"));
    StaticTextConfigFooter->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_GRAYTEXT));
    FlexGridSizer6->Add(StaticTextConfigFooter, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizerAdvanced->Add(FlexGridSizer6, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    PanelAdvanced->SetSizer(StaticBoxSizerAdvanced);
    StaticBoxSizerAdvanced->Fit(PanelAdvanced);
    StaticBoxSizerAdvanced->SetSizeHints(PanelAdvanced);
    GridBagSizerWindow->Add(PanelAdvanced, wxGBPosition(3, 0), wxGBSpan(1, 7), wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    ButtonCreate = new wxButton(this, ID_BUTTON1, _("Create SFX"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    ButtonCreate->SetFocus();
    wxFont ButtonCreateFont(wxDEFAULT,wxDEFAULT,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    ButtonCreate->SetFont(ButtonCreateFont);
    GridBagSizerWindow->Add(ButtonCreate, wxGBPosition(4, 0), wxGBSpan(1, 7), wxBOTTOM|wxALIGN_BOTTOM|wxALIGN_CENTER_HORIZONTAL, 5);
    SetSizer(GridBagSizerWindow);
    DirDialogSource = new wxDirDialog(this, _("Select directory"), wxEmptyString, wxDD_DEFAULT_STYLE, wxDefaultPosition, wxDefaultSize, _T("wxDirDialog"));
    FileDialogSource = new wxFileDialog(this, _("Select file"), wxEmptyString, wxEmptyString, wxFileSelectorDefaultWildcardStr, wxFD_DEFAULT_STYLE, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
    GridBagSizerWindow->Fit(this);
    GridBagSizerWindow->SetSizeHints(this);
    Center();

    Connect(ID_BITMAPBUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&sfxGUIDialog::OnBitmapButtonSelectFileClick);
    Connect(ID_BITMAPBUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&sfxGUIDialog::OnBitmapButtonSelectDirectoryClick);
    Connect(ID_CHOICE1,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&sfxGUIDialog::OnChoiceTypeSelect);
    Connect(ID_CHECKBOX1,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&sfxGUIDialog::OnCheckBoxAdvancedClick);
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
    }
    else
    {
        StaticTextExecute->Enable(false);
        ComboBoxExecute->Enable(false);
        CheckBoxAdvanced->Enable(false);
        PanelAdvanced->Enable(false);
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

	// re-allocate the window's size hints after set showing a hidden control
	// in order to prevent the window from being sized smaller than the minimal size required by the sizer
	GridBagSizerWindow->SetSizeHints(this); // call fit automatically

    wxCommandEvent ce;
    OnChoiceTypeSelect(ce);
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