//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include <ida.hpp>
#include <idp.hpp>
#include <loader.hpp>
#include <auto.hpp>
#include "ReadInformationInstruction.h"
//---------------------------------------------------------------------------
#pragma argsused
int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void* lpReserved)
{
        return 1;
}
//---------------------------------------------------------------------------
int idaapi init(void)
{
if ( inf.filetype == f_OMF ) return PLUGIN_SKIP;
// Don't work in text version
if ( callui(ui_get_hwnd).vptr == NULL ) return PLUGIN_SKIP;
return PLUGIN_OK;
}
//--------------------------------------------------------------------------
void idaapi term(void)
{
return;
}
//---------------------------------------------------------------------------
void idaapi run(int arg)
{
ea_t CA = get_screen_ea();
msg("PLUGIN ¹22 - Read Instruction Information \n");
Read_Information_Instruction(CA);
Read_Referens_Info(CA);
analyze_area(1,1);
}
//--------------------------------------------------------------------------
char comment[] = "Read Information Instruction";
char help[] ="Read  instruction information from current addres\n"
             "\n"
             "\n"
             "\n"
             "\n";
char wanted_name[] = "[PLUGIN ¹22] - Read Instruction Information";
char wanted_hotkey[] = "Ctrl+Alt+I";
//--------------------------------------------------------------------------
//      PLUGIN DESCRIPTION BLOCK
//--------------------------------------------------------------------------
plugin_t __declspec(dllexport) PLUGIN =
{
  IDP_INTERFACE_VERSION,
  0,                    // plugin flags
  init,                 // initialize
  term,                 // terminate. this pointer may be NULL.
  run,                  // invoke plugin
  comment,              // long comment about the plugin
                        // it could appear in the status line or as a hint
  help,                 // multiline help about the plugin
  wanted_name,          // the preferred short name of the plugin
  wanted_hotkey         // the preferred hotkey to run the plugin
};
//---------------------------------------------------------------------------

