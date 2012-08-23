#ifndef SFXGUIMAIN_H
#define SFXGUIMAIN_H

#define SFX_SOURCE wxInt8
#define SFX_SOURCE_INVALID (wxInt8)-1
#define SFX_SOURCE_FILE (wxInt8)0
#define SFX_SOURCE_DIRECTORY (wxInt8)1

#define SFX_TYPE wxInt8
#define SFX_TYPE_UNKNOWN (wxInt8)-1
#define SFX_TYPE_ARCHIVE (wxInt8)0
#define SFX_TYPE_INSTALLER (wxInt8)1

//(*Headers(sfxGUIDialog)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/choice.h>
#include <wx/button.h>
#include <wx/dirdlg.h>
#include <wx/dialog.h>
#include <wx/combobox.h>
//*)
#include <wx/dir.h>
#include <wx/textfile.h>

class sfxGUIDialog: public wxDialog
{
    public:

        sfxGUIDialog(wxWindow* parent,wxWindowID id = -1);
        virtual ~sfxGUIDialog();

    private:

        //(*Handlers(sfxGUIDialog)
        void OnButtonBrowseClick(wxCommandEvent& event);
        void OnChoiceTypeSelect(wxCommandEvent& event);
        void OnButtonCreateClick(wxCommandEvent& event);
        void OnButtonAbortClick(wxCommandEvent& event);
        //*)

        public: void SetSource(wxString source);
        private: SFX_SOURCE GetSourceType();
        private: SFX_TYPE GetSfxType();
        private: wxString GetCommand();
        private: wxString GetLauncherPath();
        private: void CreateLauncherFile(wxString path);
        private: void CreateConfigurationFile(wxString path);
        private: void EnableDisableControls(bool enable);

        //(*Identifiers(sfxGUIDialog)
        static const long ID_STATICTEXT1;
        static const long ID_TEXTCTRL1;
        static const long ID_BUTTON2;
        static const long ID_STATICTEXT4;
        static const long ID_TEXTCTRL2;
        static const long ID_CHOICE2;
        static const long ID_STATICTEXT2;
        static const long ID_CHOICE1;
        static const long ID_STATICTEXT3;
        static const long ID_COMBOBOX1;
        static const long ID_BUTTON1;
        //*)

        //(*Declarations(sfxGUIDialog)
        wxTextCtrl* TextCtrlSource;
        wxDirDialog* DirDialogSource;
        wxStaticText* StaticTextSource;
        wxStaticText* StaticTextType;
        wxButton* ButtonCreate;
        wxChoice* ChoiceCompression;
        wxComboBox* ComboBoxExecute;
        wxButton* ButtonBrowse;
        wxStaticText* StaticTextTarget;
        wxStaticText* StaticTextExecute;
        wxChoice* ChoiceType;
        wxTextCtrl* TextCtrlTarget;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // SFXGUIMAIN_H
