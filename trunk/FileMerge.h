#ifndef FILEMERGE_H
#define FILEMERGE_H

//(*Headers(FileMerge)
#include <wx/sizer.h>
#include <wx/textctrl.h>
#include <wx/listbox.h>
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/gauge.h>
//*)
#include <wx/wfstream.h>

class FileMerge: public wxDialog
{
	public:

		FileMerge(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~FileMerge();

		//(*Declarations(FileMerge)
		wxTextCtrl* TextCtrlFileOut;
		wxButton* ButtonCancel;
		wxListBox* ListBoxFilesIn;
		wxGauge* GaugeProgress;
		//*)

	protected:

		//(*Identifiers(FileMerge)
		static const long ID_LISTBOX1;
		static const long ID_TEXTCTRL1;
		static const long ID_GAUGE1;
		static const long ID_BUTTON1;
		//*)

		bool abort;

	private:

		//(*Handlers(FileMerge)
		void OnButtonCancelClick(wxCommandEvent& event);
		//*)

        private: void AppendFileToStream(wxFileOutputStream *outputStream, wxString inputFile);
        private: wxUint64 GetInputFilesSize();
        public: void MergeFiles();
        public: void AddInputFiles(wxArrayString files);
        public: void SetOutputFile(wxString file);

		DECLARE_EVENT_TABLE()
};

#endif
