#ifndef SFXGUIMAIN_H
#define SFXGUIMAIN_H

enum SFX_SOURCE
{
    SFX_SOURCE_FILE,
    SFX_SOURCE_DIRECTORY,
    SFX_SOURCE_INVALID = -1
};

enum SFX_TYPE
{
    SFX_TYPE_ARCHIVE,
    SFX_TYPE_INSTALLER,
    SFX_TYPE_UNKNOWN = -1
};

//(*Headers(sfxGUIDialog)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/checkbox.h>
#include <wx/panel.h>
#include <wx/filedlg.h>
#include <wx/hyperlink.h>
#include <wx/choice.h>
#include <wx/bmpbuttn.h>
#include <wx/gbsizer.h>
#include <wx/button.h>
#include <wx/dirdlg.h>
#include <wx/dialog.h>
#include <wx/combobox.h>
//*)
#include <wx/dir.h>
#include <wx/stdpaths.h>
#include <wx/mstream.h>
#include <wx/wfstream.h>
#include <wx/textfile.h>

#include "resource.h"

class sfxGUIDialog: public wxDialog
{
    public:

        sfxGUIDialog(wxWindow* parent,wxWindowID id = -1);
        virtual ~sfxGUIDialog();

    private:

        //(*Handlers(sfxGUIDialog)
        void OnBitmapButtonSelectDirectoryClick(wxCommandEvent& event);
        void OnChoiceTypeSelect(wxCommandEvent& event);
        void OnButtonCreateClick(wxCommandEvent& event);
        void OnButtonAbortClick(wxCommandEvent& event);
        void OnBitmapButtonSelectFileClick(wxCommandEvent& event);
        void OnCheckBoxAdvancedClick(wxCommandEvent& event);
        //*)

        public: void SetSource(wxString path);
        private: SFX_SOURCE GetSourceType(wxString path);
        private: SFX_TYPE GetSfxType();
        private: wxString Create7zCommand(wxString source, wxString target, wxInt32 compression, wxString sfx);
        private: wxString GetSfxConfiguration();
        private: void CreateFileSfxModule(wxString path, SFX_TYPE sfxType, wxString sfxConfiguration);
        private: void EnableDisableControls(bool enable);

        //(*Identifiers(sfxGUIDialog)
        static const long ID_STATICTEXT1;
        static const long ID_TEXTCTRL1;
        static const long ID_BITMAPBUTTON1;
        static const long ID_BITMAPBUTTON2;
        static const long ID_STATICTEXT4;
        static const long ID_TEXTCTRL2;
        static const long ID_CHOICE2;
        static const long ID_STATICTEXT2;
        static const long ID_CHOICE1;
        static const long ID_STATICTEXT3;
        static const long ID_COMBOBOX1;
        static const long ID_CHECKBOX1;
        static const long ID_HYPERLINKCTRL1;
        static const long ID_STATICTEXT6;
        static const long ID_TEXTCTRL3;
        static const long ID_STATICTEXT7;
        static const long ID_PANEL2;
        static const long ID_BUTTON1;
        //*)

        //(*Declarations(sfxGUIDialog)
        wxBitmapButton* BitmapButtonSelectFile;
        wxTextCtrl* TextCtrlSource;
        wxDirDialog* DirDialogSource;
        wxStaticText* StaticTextSource;
        wxStaticText* StaticTextType;
        wxHyperlinkCtrl* HyperlinkCtrlOnlineHelp;
        wxButton* ButtonCreate;
        wxChoice* ChoiceCompression;
        wxCheckBox* CheckBoxAdvanced;
        wxComboBox* ComboBoxExecute;
        wxBitmapButton* BitmapButtonSelectDirectory;
        wxStaticText* StaticTextConfigFooter;
        wxFileDialog* FileDialogSource;
        wxStaticText* StaticTextConfigHeader;
        wxStaticText* StaticTextTarget;
        wxStaticText* StaticTextExecute;
        wxChoice* ChoiceType;
        wxTextCtrl* TextCtrlAdvanced;
        wxGridBagSizer* GridBagSizerWindow;
        wxPanel* PanelAdvanced;
        wxTextCtrl* TextCtrlTarget;
        //*)

        private: wxMemoryInputStream* resourceMemoryStream;

        DECLARE_EVENT_TABLE()
};

#endif // SFXGUIMAIN_H
