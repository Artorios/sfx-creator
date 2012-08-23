#include "sfxGUIMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(sfxGUIDialog)
#include <wx/intl.h>
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
const long sfxGUIDialog::ID_BUTTON2 = wxNewId();
const long sfxGUIDialog::ID_STATICTEXT4 = wxNewId();
const long sfxGUIDialog::ID_TEXTCTRL2 = wxNewId();
const long sfxGUIDialog::ID_CHOICE2 = wxNewId();
const long sfxGUIDialog::ID_STATICTEXT2 = wxNewId();
const long sfxGUIDialog::ID_CHOICE1 = wxNewId();
const long sfxGUIDialog::ID_STATICTEXT3 = wxNewId();
const long sfxGUIDialog::ID_COMBOBOX1 = wxNewId();
const long sfxGUIDialog::ID_BUTTON1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(sfxGUIDialog,wxDialog)
    //(*EventTable(sfxGUIDialog)
    //*)
END_EVENT_TABLE()

sfxGUIDialog::sfxGUIDialog(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(sfxGUIDialog)
    wxFlexGridSizer* FlexGridSizer4;
    wxFlexGridSizer* FlexGridSizer3;
    wxFlexGridSizer* FlexGridSizer5;
    wxFlexGridSizer* FlexGridSizer2;
    wxFlexGridSizer* FlexGridSizer1;

    Create(parent, wxID_ANY, _("7z SFX Creator"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxMINIMIZE_BOX, _T("wxID_ANY"));
    FlexGridSizer1 = new wxFlexGridSizer(0, 1, 0, 0);
    FlexGridSizer1->AddGrowableCol(1);
    FlexGridSizer2 = new wxFlexGridSizer(0, 2, 0, 0);
    FlexGridSizer2->AddGrowableCol(1);
    StaticTextSource = new wxStaticText(this, ID_STATICTEXT1, _("Source:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    FlexGridSizer2->Add(StaticTextSource, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer3 = new wxFlexGridSizer(0, 2, 0, 0);
    FlexGridSizer3->AddGrowableCol(0);
    TextCtrlSource = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    TextCtrlSource->SetMinSize(wxSize(360,0));
    TextCtrlSource->Disable();
    FlexGridSizer3->Add(TextCtrlSource, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    ButtonBrowse = new wxButton(this, ID_BUTTON2, _("Browse..."), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    FlexGridSizer3->Add(ButtonBrowse, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer2->Add(FlexGridSizer3, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    StaticTextTarget = new wxStaticText(this, ID_STATICTEXT4, _("Target:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    FlexGridSizer2->Add(StaticTextTarget, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer4 = new wxFlexGridSizer(0, 2, 0, 0);
    FlexGridSizer4->AddGrowableCol(0);
    TextCtrlTarget = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    TextCtrlTarget->Disable();
    FlexGridSizer4->Add(TextCtrlTarget, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    ChoiceCompression = new wxChoice(this, ID_CHOICE2, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE2"));
    ChoiceCompression->Append(_("Store"));
    ChoiceCompression->Append(_("Fastest"));
    ChoiceCompression->Append(_("Fast"));
    ChoiceCompression->SetSelection( ChoiceCompression->Append(_("Normal")) );
    ChoiceCompression->Append(_("Maximum"));
    ChoiceCompression->Append(_("Ultra"));
    ChoiceCompression->SetHelpText(_("Compression Method"));
    FlexGridSizer4->Add(ChoiceCompression, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer2->Add(FlexGridSizer4, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    StaticTextType = new wxStaticText(this, ID_STATICTEXT2, _("Type:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    FlexGridSizer2->Add(StaticTextType, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer5 = new wxFlexGridSizer(0, 3, 0, 0);
    FlexGridSizer5->AddGrowableCol(0);
    FlexGridSizer5->AddGrowableCol(2);
    ChoiceType = new wxChoice(this, ID_CHOICE1, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
    ChoiceType->SetSelection( ChoiceType->Append(_("Self Extracting Archive")) );
    ChoiceType->Append(_("Self Extracting Installer"));
    ChoiceType->SetHelpText(_("SFX Archive:\n + extract files to a directory choosen by the user\n + usage: distribute compressed data files\n\nSFX Installer:\n + extract files to a temporary directory\n + execute a specific file after extraction\n + delete temporary files after completion\n + usage: distribute compressed applications"));
    FlexGridSizer5->Add(ChoiceType, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticTextExecute = new wxStaticText(this, ID_STATICTEXT3, _("Execute File:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    FlexGridSizer5->Add(StaticTextExecute, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    ComboBoxExecute = new wxComboBox(this, ID_COMBOBOX1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX1"));
    ComboBoxExecute->Disable();
    FlexGridSizer5->Add(ComboBoxExecute, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer2->Add(FlexGridSizer5, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    FlexGridSizer1->Add(FlexGridSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    ButtonCreate = new wxButton(this, ID_BUTTON1, _("Create SFX"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    FlexGridSizer1->Add(ButtonCreate, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(FlexGridSizer1);
    DirDialogSource = new wxDirDialog(this, _("Select directory"), wxEmptyString, wxDD_DEFAULT_STYLE, wxDefaultPosition, wxDefaultSize, _T("wxDirDialog"));
    FlexGridSizer1->Fit(this);
    FlexGridSizer1->SetSizeHints(this);
    Center();

    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&sfxGUIDialog::OnButtonBrowseClick);
    Connect(ID_CHOICE1,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&sfxGUIDialog::OnChoiceTypeSelect);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&sfxGUIDialog::OnButtonCreateClick);
    //*)
}

sfxGUIDialog::~sfxGUIDialog()
{
    //(*Destroy(sfxGUIDialog)
    //*)
}

void sfxGUIDialog::SetSource(wxString source)
{
    SetCursor(wxCURSOR_WAIT);

    TextCtrlSource->SetValue(source);
    TextCtrlTarget->Clear();
    ComboBoxExecute->Clear();

    // check if source is a valid directory
    if(GetSourceType() == SFX_SOURCE_DIRECTORY)
    {
        TextCtrlTarget->SetValue(source + wxT(".exe"));
        wxArrayString files;
        wxDir::GetAllFiles(source, &files, wxT("*.*"), wxDIR_FILES); // get all files from initial directory (no sub-directories)
        if(files.GetCount() > 0)
        {
            for(wxUint32 i=0; i<files.GetCount(); i++)
            {
                files[i].Replace(source + wxT("\\"), wxT(""));
                ComboBoxExecute->Append(files[i]);
            }
        }
    }

    // check if source is a valid file
    if(GetSourceType() == SFX_SOURCE_FILE)
    {
        TextCtrlTarget->SetValue(source.BeforeLast('.') + wxT(".sfx.exe"));
        ComboBoxExecute->Append(source.AfterLast('\\'));
    }

    // check if soure is invalid
    if(GetSourceType() == SFX_SOURCE_INVALID)
    {
        TextCtrlSource->Clear();
    }

    SetCursor(wxCURSOR_DEFAULT);
}

void sfxGUIDialog::OnButtonBrowseClick(wxCommandEvent& event)
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
        ComboBoxExecute->Enable(true);
    }
    else
    {
        ComboBoxExecute->Enable(false);
        ComboBoxExecute->Select(-1);
    }
}

SFX_SOURCE sfxGUIDialog::GetSourceType()
{
    wxString source = TextCtrlSource->GetValue();

    // Check if source is a valid directory
    if(wxDirExists(source))
    {
        return SFX_SOURCE_DIRECTORY;
    }
    // Check if source is a valid file
    if(wxFileExists(source))
    {
        return SFX_SOURCE_FILE;
    }

    return SFX_SOURCE_INVALID;
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

wxString sfxGUIDialog::GetCommand()
{
    SFX_TYPE sfxType = GetSfxType();
    SFX_SOURCE sourceType = GetSourceType();

    wxString command = wxT("7zG.exe a");

    command += wxString::Format(wxT(" -mx%i"), wxMax(0, 2*ChoiceCompression->GetSelection()-1));

    if(sfxType == SFX_TYPE_ARCHIVE)
    {
        command += wxT(" -sfx\"7z.sfx\"");
    }
    if(sfxType == SFX_TYPE_INSTALLER)
    {
        command += wxT(" -sfx\"7zS2.sfx\"");
    }

    command += wxT(" \"") + TextCtrlTarget->GetValue() + wxT("\"");
    command += wxT(" \"") + TextCtrlSource->GetValue() + wxT("\"");

    if(sourceType == SFX_SOURCE_DIRECTORY && sfxType == SFX_TYPE_INSTALLER)
    {
        command += wxT(" \"") + GetLauncherPath() + wxT("\"");
    }

    return command;
}

wxString sfxGUIDialog::GetLauncherPath()
{
    return TextCtrlTarget->GetValue().BeforeLast('\\') + wxT("\\autorun.cmd");
}

void sfxGUIDialog::CreateLauncherFile(wxString path)
{
    wxTextFile f;

    // create file, or open if already exists
    if(!f.Create(path))
    {
        f.Open(path);
        f.Clear();
    }

    f.AddLine(wxT("@ECHO OFF"));
    f.AddLine(wxT("MODE Con Cols=31 Lines=5"));
    f.AddLine(wxT("TITLE DON'T CLOSE"));
    f.AddLine(wxT("ECHO."));
    f.AddLine(wxT("ECHO ### DON'T CLOSE THIS WINDOW ###"));
    f.AddLine(wxT("ECHO."));
    if(GetSourceType() == SFX_SOURCE_DIRECTORY)
    {
        wxString cwd = TextCtrlSource->GetValue().AfterLast('\\') + wxT("\\") + ComboBoxExecute->GetValue().BeforeLast('\\');
        // if source is a directory, cwd is always valid
        //if(!cwd.IsEmpty() && cwd != wxT("\\"))
        //{
            f.AddLine(wxT("CD \"") + cwd + wxT("\""));
        //}
    }
    // FIXME: when using start without /wait , batch file exit and 7z SFX deletes temp files
    //f.AddLine(wxT("START /wait ") + ComboBoxExecute->GetValue().AfterLast('\\'));
    f.AddLine(wxT("\"") + ComboBoxExecute->GetValue().AfterLast('\\') + wxT("\""));

    f.Write();
    f.Close();
}

void sfxGUIDialog::CreateConfigurationFile(wxString path)
{
    wxTextFile f;

    // create file, or open if already exists
    if(!f.Create(path))
    {
        f.Open(path);
        f.Clear();
    }

    f.AddLine(wxT(";!@Install@!UTF-8!"));
    f.AddLine(wxT("RunProgram=\"") + ComboBoxExecute->GetValue() + wxT("\""));
    f.AddLine(wxT(";!@InstallEnd@!"));

    f.Write();
    f.Close();
}

void sfxGUIDialog::OnButtonCreateClick(wxCommandEvent& event)
{
    SetCursor(wxCURSOR_WAIT);

    EnableDisableControls(false);

    SFX_TYPE sfxType = GetSfxType();
    SFX_SOURCE sourceType = GetSourceType();
    wxString launcherPath = GetLauncherPath();

    if(sourceType == SFX_SOURCE_DIRECTORY && sfxType == SFX_TYPE_INSTALLER)
    {
        CreateLauncherFile(launcherPath);
    }

    wxExecute(GetCommand(), wxEXEC_SYNC); // EXEC_SYNC to wait for 7zip
    Raise(); // focus back to this dialog after 7zip finished

    if(sourceType == SFX_SOURCE_DIRECTORY && sfxType == SFX_TYPE_INSTALLER)
    {
        wxRemoveFile(launcherPath);
    }

    EnableDisableControls(true);

    SetCursor(wxCURSOR_DEFAULT);
}

void sfxGUIDialog::EnableDisableControls(bool enable)
{
    if(enable)
    {
        ButtonBrowse->Enable(true);
        ChoiceCompression->Enable(true);
        ChoiceType->Enable(true);
        if(GetSfxType() == SFX_TYPE_INSTALLER)
        {
            ComboBoxExecute->Enable(true);
        }
        ButtonCreate->Enable(true);
    }
    else
    {
        ButtonBrowse->Enable(false);
        ChoiceCompression->Enable(false);
        ChoiceType->Enable(false);
        ComboBoxExecute->Enable(false);
        ButtonCreate->Enable(false);
    }
}
