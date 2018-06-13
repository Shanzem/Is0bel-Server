//////////////////////////////////////////////////////////////
//
//
//	Web server progress - First server -
//
// 	Click "Play" now works and starts the server.
//	Well i have an HTTP 1.0 server. still need to add stop.
//	Destroy thread.
//
//	Will have no doubt use the third party library example for CEF. 
//	Also for getting at least HTTP 3.0+ server.
//
//	Echo server +  client slapped toghter.
//
//	Time and date server in & client.
//
//
//////////////////////////////////////////////////////////////////
//
//	Includes
//
#include <boost/thread.hpp>
#include <boost/chrono.hpp>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include "server.hpp"
#include "imgui.h"
#include "imgui_impl_dx9.h"
#include <d3d9.h>
#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>
#include <tchar.h>
#include <d3dx9.h>
#include <ctime>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include "Echo_server.hpp"
#include "Daytime_server.hpp"
//#include <boost/filesystem.hpp>
//////////////////////////////////////////////////////////////
//
//	Using section
//
using namespace std;
using boost::asio::ip::tcp;
/////////////////////////////////////////////////////////////////
//
// Web server input & outputs.
//
static char web_server_IP[256] = "127.0.0.1";
static char web_server_PORT[256] = "80";
static char web_server_webpage[256] = "C:\\";

bool web_status_empty					=	true;
bool web_status_red						=	false;
bool web_status_yellow					=	false;
bool web_status_green					=	false;
/////////////////////////////////////////////////////
//
//	FTP server inputs & outputs
//
static char ftp_server_IP[256] = "127.0.0.1";
static char ftp_server_PORT[256] = "2020";
static char ftp_server_folder[256] = "C:\\home";
bool ftp_status_empty					=	true;
bool ftp_status_red						=	false;
bool ftp_status_yellow					=	false;
bool ftp_status_green					=	false;
/////////////////////////////////////////////////////
//
//	Echo server setup
//
static char echo_server_port[256] = "3000";
bool echo_allowed_status_empty		=	true;
bool echo_allowed_status_red		=	false;
bool echo_allowed_status_yellow		=	false;
bool echo_allowed_status_green		=	false;
//////////////////////////////////////////////////////////////////
//
// Date & time server.
//
bool date_time_server_status_empty		=	true;
bool date_time_server_status_red		=	false;
bool date_time_server_status_yellow		=	false;
bool date_time_server_status_green		=	false;
///////////////////////////////////////////////////////////////
//
//	Dummy traffic
//
bool Dummytraffic_status_empty					=	true;
bool Dummytraffic_status_red					=	false;
bool Dummytraffic_status_yellow					=	false;
bool Dummytraffic_status_green					=	false;
/////////////////////////////////////////////////////////////////
//
//	IRC chat
//
bool enable_chat_status_empty					=	true;
bool enable_chat_status_red						=	false;
bool enable_chat_status_yellow					=	false;
bool enable_chat_status_green					=	false;
////////////////////////////////////////////////////////////////
//
//	VOIP
//
bool team_speak_status_empty					=	true;
bool team_speak_status_red						=	false;
bool team_speak_status_yellow					=	false;
bool team_speak_status_green					=	false;
/////////////////////////////////////////////////////////////////
//
//	Log to other
//
bool log_to_other_status_empty					=	true;
bool log_to_other_status_red					=	false;
bool log_to_other_status_yellow					=	false;
bool log_to_other_status_green					=	false;
/////////////////////////////////////////////////////////////////
//
//	Is0bel states
//
bool startup_shutdown_status_empty				=	true;
bool startup_shutdown_status_red				=	false;
bool startup_shutdown_status_yellow				=	false;
bool startup_shutdown_status_green				=	false;
/////////////////////////////////////////////////////////////////
//
//	Automation
//
bool automation_status_empty					=	true;
bool automation_status_red						=	false;
bool automation_status_yellow					=	false;
bool automation_status_green					=	false;
/////////////////////////////////////////////////////////////////
//
//	Contribution
//
bool cycles_contribution_status_empty			=	true;
bool cycles_contribution_status_red				=	false;
bool cycles_contribution_status_yellow			=	false;
bool cycles_contribution_status_green			=	false;
/////////////////////////////////////////////////////////////////
//
//	preventative maintenance
//
bool preventative_maintenance_status_empty		=	true;
bool preventative_maintenance_status_red		=	false;
bool preventative_maintenance_status_yellow		=	false;
bool preventative_maintenance_status_green		=	false;
/////////////////////////////////////////////////////////////////
//
//	MySQL
//
bool mysql_database_custom_status_empty			=	true;
bool mysql_database_custom_status_red			=	false;
bool mysql_database_custom_status_yellow		=	false;
bool mysql_database_custom_status_green			=	false;
/////////////////////////////////////////////////////////////////
//
//	Bandwidth monitor
//
bool bandwidth_monitor_status_empty				=	true;
bool bandwidth_monitor_status_red				=	false;
bool bandwidth_monitor_status_yellow			=	false;
bool bandwidth_monitor_status_green				=	false;
/////////////////////////////////////////////////////////////////
//
//	IoT Devices
//
bool IoT_device_relay_or_storage_status_empty	=	true;
bool IoT_device_relay_or_storage_status_red		=	false;
bool IoT_device_relay_or_storage_status_yellow	=	false;
bool IoT_device_relay_or_storage_status_green	=	false;
/////////////////////////////////////////////////////////////////
//
//	LAN
//
bool local_area_network_status_empty			=	true;
bool local_area_network_status_red				=	false;
bool local_area_network_status_yellow			=	false;
bool local_area_network_status_green			=	false;
/////////////////////////////////////////////////////////////////
//
//	Ret-Dec services
//
bool retargetable_decompiler_status_empty		=	true;
bool retargetable_decompiler_status_red			=	false;
bool retargetable_decompiler_status_yellow		=	false;
bool retargetable_decompiler_status_green		=	false;
/////////////////////////////////////////////////////////////////
//
//	S2S idea
//
bool s2s_server_services_status_empty			=	true;
bool s2s_server_services_status_red				=	false;
bool s2s_server_services_status_yellow			=	false;
bool s2s_server_services_status_green			=	false;
//////////////////////////////////////////////////////////////////
//
//			
//	Threading calls, or current working services/servers
//	found here.
//
//void Print1() 
//{
//boost::this_thread::sleep_for(boost::chrono::milliseconds{500});
//system("cmd");
//}
void Web_server_check() 
{
system("ipconfigure.netstat.a.bat");
}
void ipconfigure() 
{
system("ipconfigure.bat");
}
void ipconfigure_netstat_a() 
{
system("ipconfigure.netstat.a.bat");
}
void ipconfigure_netstat_f() 
{
system("ipconfigure.netstat.f.bat");
}
void ipconfigure_netstat_o() 
{
system("ipconfigure.netstat.o.bat");
}
void ipconfigure_netstat_on() 
{
system("ipconfigure.netstat.on.bat");
}
void ipconfigure_netstat_t() 
{
system("ipconfigure.netstat.t.bat");
}
void ipconfigure_wmic() 
{
system("ipconfigure.wmic.bat");
}
void ipconfigure_wmic_help() 
{
system("ipconfigure.wmic.help.bat");
}
void ImGui_web_server_start() 
{
web_status_empty	=	false;
web_status_green	=	true;
http::server::server s(web_server_IP, web_server_PORT, web_server_webpage);
s.run();
}
void ImGui_echo_server_start() 
{
echo_allowed_status_empty	=	false;
echo_allowed_status_green	=	true;	
boost::asio::io_context io_context;
server s(io_context, atoi(echo_server_port));
io_context.run();
}
void echo_client_test() 
{
system("Echo.Client.test.bat");
}
void daytime_server_start()
{
date_time_server_status_empty		=	false;
date_time_server_status_green		=	true;
boost::asio::io_context io_context;
tcp_server server(io_context);
io_context.run();	
}
void Date_time_client_start()
{
system("Time.date.client.start.bat");
}
//////////////////////////////////////////////////////////////////
// Data
static LPDIRECT3DDEVICE9        g_pd3dDevice = NULL;
static D3DPRESENT_PARAMETERS    g_d3dpp;

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
        return true;

    switch (msg)
    {
    case WM_SIZE:
        if (g_pd3dDevice != NULL && wParam != SIZE_MINIMIZED)
        {
            ImGui_ImplDX9_InvalidateDeviceObjects();
            g_d3dpp.BackBufferWidth  = LOWORD(lParam);
            g_d3dpp.BackBufferHeight = HIWORD(lParam);
            HRESULT hr = g_pd3dDevice->Reset(&g_d3dpp);
            if (hr == D3DERR_INVALIDCALL)
                IM_ASSERT(0);
            ImGui_ImplDX9_CreateDeviceObjects();
        }
        return 0;
    case WM_SYSCOMMAND:
        if ((wParam & 0xfff0) == SC_KEYMENU) // Disable ALT application menu
            return 0;
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hWnd, msg, wParam, lParam);
}

int main(int, char**)
{

    // Create application window
    WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_CLASSDC, WndProc, 0L, 0L, GetModuleHandle(NULL), NULL, LoadCursor(NULL, IDC_ARROW), NULL, NULL, _T("ImGui Example"), NULL };
    RegisterClassEx(&wc);
    HWND hwnd = CreateWindow(_T("ImGui Example"), _T("Is0bel Server -ISO-"), WS_OVERLAPPEDWINDOW, 0, 0, 1280, 800, NULL, NULL, wc.hInstance, NULL);

    // Initialize Direct3D
    LPDIRECT3D9 pD3D;
    if ((pD3D = Direct3DCreate9(D3D_SDK_VERSION)) == NULL)
    {
        UnregisterClass(_T("ImGui Example"), wc.hInstance);
        return 0;
    }
    ZeroMemory(&g_d3dpp, sizeof(g_d3dpp));
    g_d3dpp.Windowed = TRUE;
    g_d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
    g_d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
    g_d3dpp.EnableAutoDepthStencil = TRUE;
    g_d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
    g_d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_ONE; // Present with vsync

    //g_d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE; // Present without vsync, maximum unthrottled framerate

    // Create the D3DDevice
    if (pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hwnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &g_d3dpp, &g_pd3dDevice) < 0)
    {
        pD3D->Release();
        UnregisterClass(_T("ImGui Example"), wc.hInstance);
        return 0;
    }

    // Setup ImGui binding
    ImGui_ImplDX9_Init(hwnd, g_pd3dDevice);

    // Setup style
    ImGui::StyleColorsDark();
    //ImGui::StyleColorsClassic();

    // Load Fonts
    // - If no fonts are loaded, dear imgui will use the default font. You can also load multiple fonts and use ImGui::PushFont()/PopFont() to select them.
    // - AddFontFromFileTTF() will return the ImFont* so you can store it if you need to select the font among multiple.
    // - If the file cannot be loaded, the function will return NULL. Please handle those errors in your application (e.g. use an assertion, or display an error and quit).
    // - The fonts will be rasterized at a given size (w/ oversampling) and stored into a texture when calling ImFontAtlas::Build()/GetTexDataAsXXXX(), which ImGui_ImplXXXX_NewFrame below will call.
    // - Read 'misc/fonts/README.txt' for more instructions and details.
    // - Remember that in C/C++ if you want to include a backslash \ in a string literal you need to write a double backslash \\ !
    //ImGuiIO& io = ImGui::GetIO();
    //io.Fonts->AddFontDefault();
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/Roboto-Medium.ttf", 16.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/Cousine-Regular.ttf", 15.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/DroidSans.ttf", 16.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/ProggyTiny.ttf", 10.0f);
    //ImFont* font = io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\ArialUni.ttf", 18.0f, NULL, io.Fonts->GetGlyphRangesJapanese());
    //IM_ASSERT(font != NULL);

//////////////////////////////////////////////////////////////
//
//	Window bools
//
/////////////////////////////////////////////////////////////
bool show_server_main				=	true;		// Main setup
bool show_save_complete				= 	false;		// Clickable
bool show_about_server				= 	false;		// Blurb
bool show_web_help					=	false;		// About web server
bool show_ftp_help					=	false;		// About ftp details
bool show_network_tools_help		=	false;		// Details about tools
bool show_HTTP_settings				=	false;		// Shows HTTP advanced settings
bool show_FTP_settings				=	false;		// Shows FTP advanced settings
bool show_FTP_white_list			=	false;		// Shows FTP white list
bool show_FTP_permissions			=	false;		// Shows FTP permissions
bool show_network_tools_logging		=	false;		// Show network IP logging
bool show_network_tools_blocked		=	false;		// Show network IP block list
bool show_network_tools_FTP_log		=	false;		// Show network FTP activities logging & events
bool show_network_tools_admin		=	false;		// Show Admin tools,
bool show_new_code_area				=	false;		// Shows new coding area outputs.
///////////////////////////////////////////////////////////
//
//	Images & icons
//
static LPDIRECT3DTEXTURE9       statusempty		= NULL;
static LPDIRECT3DTEXTURE9       statusred		= NULL;
static LPDIRECT3DTEXTURE9       statusyellow	= NULL;
static LPDIRECT3DTEXTURE9       statusgreen		= NULL;
static LPDIRECT3DTEXTURE9       pause			= NULL;
static LPDIRECT3DTEXTURE9       stop	 		= NULL;
static LPDIRECT3DTEXTURE9       resume			= NULL;
static LPDIRECT3DTEXTURE9       web 			= NULL;
static LPDIRECT3DTEXTURE9       home 			= NULL;
static LPDIRECT3DTEXTURE9       back 			= NULL;
static LPDIRECT3DTEXTURE9       forward 		= NULL;
static LPDIRECT3DTEXTURE9       downloads		= NULL;
static LPDIRECT3DTEXTURE9       bookmarks		= NULL;
static LPDIRECT3DTEXTURE9       settings 		= NULL;
static LPDIRECT3DTEXTURE9       source 			= NULL;

D3DXCreateTextureFromFile( g_pd3dDevice, "source.png" ,		 &source );
D3DXCreateTextureFromFile( g_pd3dDevice, "statusempty.png" , &statusempty );
D3DXCreateTextureFromFile( g_pd3dDevice, "statusred.png" , 	 &statusred );
D3DXCreateTextureFromFile( g_pd3dDevice, "statusyellow.png" ,&statusyellow );
D3DXCreateTextureFromFile( g_pd3dDevice, "statusgreen.png" , &statusgreen );
D3DXCreateTextureFromFile( g_pd3dDevice, "pause.png" , 		 &pause );
D3DXCreateTextureFromFile( g_pd3dDevice, "run.png" , 		 &resume );
D3DXCreateTextureFromFile( g_pd3dDevice, "stop.png" ,		 &stop );
D3DXCreateTextureFromFile( g_pd3dDevice, "web.png" ,	 	 &web );
D3DXCreateTextureFromFile( g_pd3dDevice, "home.png" ,	 	 &home );
D3DXCreateTextureFromFile( g_pd3dDevice, "back.png" ,	 	 &back );
D3DXCreateTextureFromFile( g_pd3dDevice, "forward.png" ,	 &forward );
D3DXCreateTextureFromFile( g_pd3dDevice, "stop.png" ,		 &stop );
D3DXCreateTextureFromFile( g_pd3dDevice, "downloads.png" ,	 &downloads );
D3DXCreateTextureFromFile( g_pd3dDevice, "bookmarks.png" ,	 &bookmarks );
D3DXCreateTextureFromFile( g_pd3dDevice, "mechanical.png" ,	 &settings );
//////////////////////////////////////////////////////////
//
// Server start/pause/stop select & status
//
bool web_server_start					=	false;
bool ftp_server_start					=	false;
bool network_server_start				=	false;

bool web_server_pause					=	false;
bool ftp_server_pause					=	false;
bool network_server_pause				=	false;

bool web_server_stop					=	false;
bool ftp_server_stop					=	false;
bool network_server_stop				=	false;
//////////////////////////////////////////////////////////////
//
//	Redudent bools 
//	to be moved to there own place within source.
//
bool Dummytraffic 						=	false;
bool echo_allowed						=	false;
bool enable_chat						=	false;
bool team_speak							=	false;
bool log_to_other						=	false;
bool startup_shutdown					=	false;
bool automation							=	false;
bool cycles_contribution				=	false;
bool preventative_maintenance			=	false;
bool mysql_database_custom				=	false;
bool date_time_server					=	false;
bool bluetooth_to_network_adapter		=	false;
bool bandwidth_monitor					=	false;
bool IoT_device_relay_or_storage		=	false;
bool local_area_network					=	false;
bool stop_all_services					=	false;
bool active_file_transfers				=	false;
bool Web_page_hits						=	false;
bool all_services_uptime				=	false;          
bool retargetable_decompiler			=	false;        
bool s2s_server_services				=	false;
////////////////////////////////////////////////////
//
//	Network tools setup bools
//
bool Dummytraffic_setup					=	false;
bool echo_allowed_setup					=	false;
bool enable_chat_setup					=	false;
bool team_speak_setup					=	false;
bool log_to_other_setup					=	false;
bool startup_shutdown_setup				=	false;
bool automation_setup					=	false;
bool cycles_contribution_setup			=	false;
bool preventative_maintenance_setup		=	false;
bool mysql_database_custom_setup		=	false;
bool date_time_server_setup				=	false;
bool bluetooth_to_network_adapter_setup	=	false;
bool bandwidth_monitor_setup			=	false;
bool IoT_device_relay_or_storage_setup	=	false;
bool local_area_network_setup			=	false;
bool retargetable_decompiler_setup		=	false;
bool s2s_server_services_setup			=	false;

////////////////////////////////////////////////////////////
//
//	Screen RGBA
//
ImVec4 clear_color = ImVec4(0.073f, 0.115f, 0.177f, 1.000f); 
//////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
//
// Web browser bool & functionality.
//
//
bool show_web_browser			= false;		// Browser.
bool show_web_settings			= false;		// Homepage/Downloads location/ssl/ftp/others
bool save_ftp_login				= false;		// Saved as binary fileformat. STILL WIP
bool mobile_html				= false;		// Mobile phone HTML only. look into me more.
bool status_empty				= true;			// Connection status indicators.
bool status_red					= false;		// "
bool status_yellow				= false;		// "
bool status_green				= false;		// "
bool save_cloud_login			= false;		// Saved as binary fileformat. STILL WIP
bool show_download_manager		= false;		// Used for upstream/downstream progress.
bool show_bookmarks_saved		= false;		// Displays user defined bookmarks

static char bookmarks_kept[1024*16];			// Bookmarks for browser.


static ImGuiOnceUponAFrame Browser_settings;	// Bookmarks & browser settings.
				if (Browser_settings)			// Will have to use my regex load here to parse data.
					{
            			ifstream file("Bookmarks.setting", ios::in|ios::ate);
            			if (file.is_open())
            				{						
							streampos size;			
					  		size = file.tellg();
							file.seekg (0, ios::beg);
							file.read (bookmarks_kept, size);
							file.close();
							}
					}
///////////////////////////////////////////////////////////
//
// Webserver settings. Loading preset.
//WIP
//
//
//
//static ImGuiOnceUponAFrame web_settings;	// Web.server settings.
//				if (web_settings)			// Will have to use my regex load here to parse data.
//					{
//            			ifstream file("WEB.server.setting", ios::in|ios::ate);
//            			if (file.is_open())
//            				{						
//							streampos size;			
//					  		size = file.tellg();
//							file.seekg (0, ios::beg);
//							file.read (bookmarks_kept, size);
//							file.close();
//							}
//					}									
//////////////////////////////////////////////////////////
//
// FTP server loading area
//
//
//
//
//static ImGuiOnceUponAFrame FTP_settings;	// FTP.server settings.
//				if (FTP_settings)			// Will have to use my regex load here to parse data.
//					{
//            			ifstream file("FTP.server.setting", ios::in|ios::ate);
//            			if (file.is_open())
//            				{						
//							streampos size;			
//					  		size = file.tellg();
//							file.seekg (0, ios::beg);
//							file.read (bookmarks_kept, size);
//							file.close();
//							}
//					}
/////////////////////////////////////////////////////////						            
			
  // Main loop
    MSG msg;
    ZeroMemory(&msg, sizeof(msg));
    ShowWindow(hwnd, SW_SHOWDEFAULT);
    UpdateWindow(hwnd);
    while (msg.message != WM_QUIT)
    {
        // You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
        // - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application.
        // - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application.
        // Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.
        if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
            continue;
        }									  
        ImGui_ImplDX9_NewFrame();             
///////////////////////////////////////////////////////////
//
//	New code proving ground.
//
//	All new code dumped into test headers.
//
//		
		if(show_new_code_area)
		{
			ImGui::Begin("Code Blocks", &show_new_code_area);
//////////////////////////////////////////////////////////////
//
// Currently unused code
//
//			

			
			if (ImGui::CollapsingHeader("Threading tests")) 
            {
            ImGui::Text("Testing threading");
            ImGui::Text("");
            ImGui::Text("Main interface threaded");
			ImGui::Text("Web browser settings still not.");
			ImGui::Text("");
			if(ImGui::Button("NETSTAT -A"))
			{
				static ImGuiOnceUponAFrame test;
				if (test)
				{
					boost::thread_group threads;
					threads.create_thread(Web_server_check);
				}	
			}
			}
			
			ImGui::Separator();
			ImGui::End();
		}
/////////////////////////////////////////////////////////////////
//
//	Main window call.
//
		show_server_main	=	true;
		
		
		if(show_server_main)
		{
			ImGui::SetNextWindowSize(ImVec2(970,535));
			ImGui::Begin("Is0bel server", &show_server_main, ImGuiWindowFlags_NoScrollbar  | ImGuiWindowFlags_NoResize);
			ImGui::Text("");
			ImGui::Text(" Web server:");
			ImGui::SameLine();
			if(ImGui::SmallButton("?##web")){show_web_help = true;}
			if (ImGui::IsItemHovered()){ImGui::BeginTooltip();ImGui::Text("Click for Web server help");ImGui::EndTooltip();}
			ImGui::SameLine(315);
			ImGui::Text(" FTP server:");
			ImGui::SameLine();
			if(ImGui::SmallButton("?##ftp")){show_ftp_help = true;}
			if (ImGui::IsItemHovered()){ImGui::BeginTooltip();ImGui::Text("Click for FTP server help");ImGui::EndTooltip();}
			ImGui::SameLine(615);
			ImGui::Text("  Network tools:");
			ImGui::SameLine();
			if(ImGui::SmallButton("?##tools")){show_network_tools_help = true;}
			if (ImGui::IsItemHovered()){ImGui::BeginTooltip();ImGui::Text("Click for Network tools help");ImGui::EndTooltip();}
			ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 5.0f);
            ImGui::BeginChild("####Webserver", ImVec2(300,400), true,ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);
            ImGui::Text("Web server settings:");
			if(ImGui::Button("HTTP Settings")){show_HTTP_settings=true;}
            ImGui::Separator();
        	ImGui::PushItemWidth(-1);
			ImGui::Text("");
			ImGui::Text("Web Server IP:");
            ImGui::InputText("###web_server_ip", web_server_IP, IM_ARRAYSIZE(web_server_IP), ImGuiInputTextFlags_CharsNoBlank | ImGuiInputTextFlags_AutoSelectAll);
			ImGui::Separator();
			ImGui::Text("");
            ImGui::Text("Web Server PORT:");
            ImGui::InputText("###web_server_port", web_server_PORT, IM_ARRAYSIZE(web_server_PORT), ImGuiInputTextFlags_CharsNoBlank | ImGuiInputTextFlags_AutoSelectAll);
			ImGui::Separator();
			ImGui::Text("");
			ImGui::Text("Webpage to display:");
			ImGui::InputText("###web_server_webpage", web_server_webpage, IM_ARRAYSIZE(web_server_webpage), ImGuiInputTextFlags_CharsNoBlank | ImGuiInputTextFlags_AutoSelectAll);
			ImGui::Separator();
			ImGui::Text("");
			ImGui::PopItemWidth();
			ImGui::EndChild();
            ImGui::SameLine();
            ImGui::BeginChild("####FTPserver", ImVec2(300,400), true,ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);
            ImGui::Text("FTP server settings:");
			if(ImGui::Button("FTP Settings")){show_FTP_settings=true;}
            ImGui::SameLine();
            if(ImGui::Button("White list")){show_FTP_white_list=true;}
            ImGui::SameLine();
            if(ImGui::Button("Permissions")){show_FTP_permissions=true;}
            ImGui::Separator();
			ImGui::PushItemWidth(-1);
			ImGui::Text("");
			ImGui::Text("FTP Server IP:");
            ImGui::InputText("###FTP_server_ip", ftp_server_IP, IM_ARRAYSIZE(ftp_server_IP), ImGuiInputTextFlags_CharsNoBlank | ImGuiInputTextFlags_AutoSelectAll);
			ImGui::Separator();
			ImGui::Text("");
            ImGui::Text("FTP Server PORT:");
            ImGui::InputText("###ftp_server_PORT", ftp_server_PORT, IM_ARRAYSIZE(ftp_server_PORT), ImGuiInputTextFlags_CharsNoBlank | ImGuiInputTextFlags_AutoSelectAll);
			ImGui::Separator();
			ImGui::Text("");
			ImGui::Text("FTP Index folder:");
			ImGui::InputText("###ftp_server_folder", ftp_server_folder, IM_ARRAYSIZE(ftp_server_folder), ImGuiInputTextFlags_CharsNoBlank | ImGuiInputTextFlags_AutoSelectAll);
			ImGui::Separator();
			ImGui::PopItemWidth();
			ImGui::EndChild();
			ImGui::SameLine();
			ImGui::BeginChild("####Network_tools", ImVec2(340,400), true);
            ImGui::PushItemWidth(-1);
			ImGui::Text("IP Logs & Block lists & Tools:");
			ImGui::Separator();
			if(ImGui::Button("Administrative")){show_network_tools_admin=true;}
			ImGui::SameLine();
			if(ImGui::Button("Web browser")){show_web_browser = true;}
			ImGui::SameLine();
			if (ImGui::Button("About")){show_about_server = true;}
			ImGui::SameLine();
			ImGui::Button("Snap-on");
			ImGui::Separator();
			if(ImGui::Button("Logging")){show_network_tools_logging=true;}
			ImGui::SameLine();
			if(ImGui::Button("Blocked")){show_network_tools_blocked=true;}
			ImGui::SameLine();
			if(ImGui::Button("Activities FTP/L")){show_network_tools_FTP_log=true;}
            ImGui::SameLine();
			ImGui::Button("Kit Box");
			ImGui::Separator();
            static int Maintenance_start = 1;
            ImGui::PushID(Maintenance_start);
			ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(0.2f, 2.0f, 0.6f));      
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(0.2f, 6.0f, 0.9f));
			ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(0.2f, 2.0f, 0.6f));
            ImGui::Button("Start##1");
  			ImGui::PopStyleColor(3);
            ImGui::PopID();          
            ImGui::SameLine();
            static int Maintenance_STOP = 1;
            ImGui::PushID(Maintenance_STOP);                 
            ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(4.0f, 0.3f, 0.7f));      
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(2.0f, 0.8f, 0.7f));
            ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(4.0f, 0.3f, 0.8f));
            ImGui::Button("Stop##1");
            ImGui::PopStyleColor(3);
            ImGui::PopID();		
            ImGui::SameLine();
            ImGui::Text("Maintenance");
			ImGui::SameLine(230);
            ImGui::SmallButton("?##1");
            if (ImGui::IsItemHovered()){ImGui::BeginTooltip();ImGui::Text(" Preventative maintenance\n\n Spybot scanning\n Virus checks\n Scheduled restarts\n Garbage collection");ImGui::EndTooltip();}
			ImGui::SameLine();
			if(ImGui::Button("Setup##1")){preventative_maintenance_setup=true;}
			ImGui::SameLine();
			if(preventative_maintenance_status_empty){if(ImGui::ImageButton((void *)statusempty, ImVec2(16, 16), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}}
			if(preventative_maintenance_status_red){if(ImGui::ImageButton((void *)statusred, ImVec2(16, 16), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}}
			if(preventative_maintenance_status_yellow){if(ImGui::ImageButton((void *)statusyellow, ImVec2(16, 16), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}}
			if(preventative_maintenance_status_green){if(ImGui::ImageButton((void *)statusgreen, ImVec2(16, 16), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}}
			if (ImGui::IsItemHovered()){ImGui::BeginTooltip();ImGui::Text("Status - Click for details.");ImGui::EndTooltip();}
			ImGui::Separator();
			static int Dummy_Traffic_start = 1;
            ImGui::PushID(Dummy_Traffic_start);
			ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(0.2f, 2.0f, 0.6f));      
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(0.2f, 6.0f, 0.9f));
			ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(0.2f, 2.0f, 0.6f));
            ImGui::Button("Start##2");
            ImGui::PopStyleColor(3);
            ImGui::PopID();
            ImGui::SameLine();
            static int Dummy_Traffic_STOP = 1;
            ImGui::PushID(Dummy_Traffic_STOP);                 
            ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(4.0f, 0.3f, 0.7f));      
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(2.0f, 0.8f, 0.7f));
            ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(4.0f, 0.3f, 0.8f));
            ImGui::Button("Stop##2");
            ImGui::PopStyleColor(3);
            ImGui::PopID();	
            ImGui::SameLine();
            ImGui::Text("Dummy Traffic");
			ImGui::SameLine(230);
            ImGui::SmallButton("?##2");
            if (ImGui::IsItemHovered()){ImGui::BeginTooltip();ImGui::Text(" Test outbound tcp/ip\n\n Send packets of dummy data on specified\n IP:PORT at specified intervals");ImGui::EndTooltip();}
			ImGui::SameLine();
			if(ImGui::Button("Setup##2")){Dummytraffic_setup=true;}
			ImGui::SameLine();
			if(Dummytraffic_status_empty){if(ImGui::ImageButton((void *)statusempty, ImVec2(16, 16), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}}
			if(Dummytraffic_status_red){if(ImGui::ImageButton((void *)statusred, ImVec2(16, 16), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}}
			if(Dummytraffic_status_yellow){if(ImGui::ImageButton((void *)statusyellow, ImVec2(16, 16), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}}
			if(Dummytraffic_status_green){if(ImGui::ImageButton((void *)statusgreen, ImVec2(16, 16), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}}
			if (ImGui::IsItemHovered()){ImGui::BeginTooltip();ImGui::Text("Status - Click for details.");ImGui::EndTooltip();}
			ImGui::Separator();
			static int Echo_Allowed_start = 1;
            ImGui::PushID(Echo_Allowed_start);
			ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(0.2f, 2.0f, 0.6f));      
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(0.2f, 6.0f, 0.9f));
			ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(0.2f, 2.0f, 0.6f));
            if(ImGui::Button("Start##3")){boost::thread_group threads;threads.create_thread(ImGui_echo_server_start);}
			ImGui::PopStyleColor(3);
            ImGui::PopID();
			ImGui::SameLine();
			static int Echo_Allowed_STOP = 1;
            ImGui::PushID(Echo_Allowed_STOP);                 
            ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(4.0f, 0.3f, 0.7f));      
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(2.0f, 0.8f, 0.7f));
            ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(4.0f, 0.3f, 0.8f));
            if(ImGui::Button("Stop##3")){}
            ImGui::PopStyleColor(3);
            ImGui::PopID();	
			ImGui::SameLine();
			ImGui::Text("Echo Allowed");
			ImGui::SameLine(230);
			ImGui::SmallButton("?##3");
			if (ImGui::IsItemHovered()){ImGui::BeginTooltip();ImGui::Text(" Test inbound tcp/ip\n\n Send a string packet to server\n Receive an echo of the string sent");ImGui::EndTooltip();}
			ImGui::SameLine();
			if(ImGui::Button("Setup##3")){echo_allowed_setup=true;}
			ImGui::SameLine();
			if(echo_allowed_status_empty){if(ImGui::ImageButton((void *)statusempty, ImVec2(16, 16), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}}
			if(echo_allowed_status_red){if(ImGui::ImageButton((void *)statusred, ImVec2(16, 16), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}}
			if(echo_allowed_status_yellow){if(ImGui::ImageButton((void *)statusyellow, ImVec2(16, 16), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}}
			if(echo_allowed_status_green){if(ImGui::ImageButton((void *)statusgreen, ImVec2(16, 16), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}}
			if (ImGui::IsItemHovered()){ImGui::BeginTooltip();ImGui::Text("Status - Click for details.");ImGui::EndTooltip();}
			ImGui::Separator();
			static int Enable_chat_start = 1;
            ImGui::PushID(Enable_chat_start);
			ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(0.2f, 2.0f, 0.6f));      
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(0.2f, 6.0f, 0.9f));
			ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(0.2f, 2.0f, 0.6f));
            ImGui::Button("Start##4");
            ImGui::PopStyleColor(3);
            ImGui::PopID();
            ImGui::SameLine();
            static int Enable_chat_STOP = 1;
            ImGui::PushID(Enable_chat_STOP);                 
            ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(4.0f, 0.3f, 0.7f));      
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(2.0f, 0.8f, 0.7f));
            ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(4.0f, 0.3f, 0.8f));
            ImGui::Button("Stop##4");
            ImGui::PopStyleColor(3);
            ImGui::PopID();	
            ImGui::SameLine();
            ImGui::Text("Enable chat");
			ImGui::SameLine(230);
            ImGui::SmallButton("?##4");
            if (ImGui::IsItemHovered()){ImGui::BeginTooltip();ImGui::Text(" Internet relay chat\n\n IRC server setup\n Admin bot setup \n Activities");ImGui::EndTooltip();}
			ImGui::SameLine();
			if(ImGui::Button("Setup##4")){enable_chat_setup=true;}
			ImGui::SameLine();
			if(enable_chat_status_empty){if(ImGui::ImageButton((void *)statusempty, ImVec2(16, 16), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}}
			if(enable_chat_status_red){if(ImGui::ImageButton((void *)statusred, ImVec2(16, 16), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}}
			if(enable_chat_status_yellow){if(ImGui::ImageButton((void *)statusyellow, ImVec2(16, 16), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}}
			if(enable_chat_status_green){if(ImGui::ImageButton((void *)statusgreen, ImVec2(16, 16), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}}
			if (ImGui::IsItemHovered()){ImGui::BeginTooltip();ImGui::Text("Status - Click for details.");ImGui::EndTooltip();}
			ImGui::Separator();
			static int Teamspeak_Server_start = 1;
            ImGui::PushID(Teamspeak_Server_start);
			ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(0.2f, 2.0f, 0.6f));      
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(0.2f, 6.0f, 0.9f));
			ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(0.2f, 2.0f, 0.6f));
            ImGui::Button("Start##5");
            ImGui::PopStyleColor(3);
            ImGui::PopID();
            ImGui::SameLine();
            static int Teamspeak_Server_STOP = 1;
            ImGui::PushID(Teamspeak_Server_STOP);                 
            ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(4.0f, 0.3f, 0.7f));      
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(2.0f, 0.8f, 0.7f));
            ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(4.0f, 0.3f, 0.8f));
            ImGui::Button("Stop##5");
            ImGui::PopStyleColor(3);
            ImGui::PopID();
            ImGui::SameLine();
            ImGui::Text("Teamspeak Server");
			ImGui::SameLine(230);
            ImGui::SmallButton("?##5");
            if (ImGui::IsItemHovered()){ImGui::BeginTooltip();ImGui::Text(" VOIP Comms\n\n Hosting\n Setup");ImGui::EndTooltip();}
			ImGui::SameLine();
			if(ImGui::Button("Setup##5")){team_speak_setup=true;}
			ImGui::SameLine();
			if(team_speak_status_empty){if(ImGui::ImageButton((void *)statusempty, ImVec2(16, 16), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}}
			if(team_speak_status_red){if(ImGui::ImageButton((void *)statusred, ImVec2(16, 16), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}}
			if(team_speak_status_yellow){if(ImGui::ImageButton((void *)statusyellow, ImVec2(16, 16), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}}
			if(team_speak_status_green){if(ImGui::ImageButton((void *)statusgreen, ImVec2(16, 16), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}}
			if (ImGui::IsItemHovered()){ImGui::BeginTooltip();ImGui::Text("Status - Click for details.");ImGui::EndTooltip();}
			ImGui::Separator();
			static int Log_forwarding_start = 1;
            ImGui::PushID(Log_forwarding_start);
			ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(0.2f, 2.0f, 0.6f));      
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(0.2f, 6.0f, 0.9f));
			ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(0.2f, 2.0f, 0.6f));
            ImGui::Button("Start##6");
            ImGui::PopStyleColor(3);
            ImGui::PopID();
            ImGui::SameLine();
            static int Log_forwarding_STOP = 1;
            ImGui::PushID(Log_forwarding_STOP);                 
            ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(4.0f, 0.3f, 0.7f));      
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(2.0f, 0.8f, 0.7f));
            ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(4.0f, 0.3f, 0.8f));
            ImGui::Button("Stop##6");
            ImGui::PopStyleColor(3);
            ImGui::PopID();
            ImGui::SameLine();
            ImGui::Text("Log forwarding");
			ImGui::SameLine(230);
            ImGui::SmallButton("?##6");
            if (ImGui::IsItemHovered()){ImGui::BeginTooltip();ImGui::Text(" Logging to other device\n\n E-mail event logging\n Devices\n priorities");ImGui::EndTooltip();}
			ImGui::SameLine();
			if(ImGui::Button("Setup##6")){log_to_other_setup=true;}
			ImGui::SameLine();
			if(log_to_other_status_empty){if(ImGui::ImageButton((void *)statusempty, ImVec2(16, 16), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}}
			if(log_to_other_status_red){if(ImGui::ImageButton((void *)statusred, ImVec2(16, 16), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}}
			if(log_to_other_status_yellow){if(ImGui::ImageButton((void *)statusyellow, ImVec2(16, 16), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}}
			if(log_to_other_status_green){if(ImGui::ImageButton((void *)statusgreen, ImVec2(16, 16), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}}
			if (ImGui::IsItemHovered()){ImGui::BeginTooltip();ImGui::Text("Status - Click for details.");ImGui::EndTooltip();}			
			ImGui::Separator();
			static int TCP_sleep_start = 1;
            ImGui::PushID(TCP_sleep_start);
			ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(0.2f, 2.0f, 0.6f));      
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(0.2f, 6.0f, 0.9f));
			ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(0.2f, 2.0f, 0.6f));
            ImGui::Button("Start##7");
            ImGui::PopStyleColor(3);
            ImGui::PopID();
            ImGui::SameLine();
            static int TCP_sleep_STOP = 1;
            ImGui::PushID(TCP_sleep_STOP);                 
            ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(4.0f, 0.3f, 0.7f));      
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(2.0f, 0.8f, 0.7f));
            ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(4.0f, 0.3f, 0.8f));
            ImGui::Button("Stop##7");
            ImGui::PopStyleColor(3);
            ImGui::PopID();	
            ImGui::SameLine();
            ImGui::Text("TCP Wakeup/sleep");
			ImGui::SameLine(230);
            ImGui::SmallButton("?##7");
            if (ImGui::IsItemHovered()){ImGui::BeginTooltip();ImGui::Text(" Wakeup / Sleep commands\n\n Lock - key");ImGui::EndTooltip();}
			ImGui::SameLine();
			if(ImGui::Button("Setup##7")){startup_shutdown_setup=true;}
			ImGui::SameLine();
			if(startup_shutdown_status_empty){if(ImGui::ImageButton((void *)statusempty, ImVec2(16, 16), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}}
			if(startup_shutdown_status_red){if(ImGui::ImageButton((void *)statusred, ImVec2(16, 16), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}}
			if(startup_shutdown_status_yellow){if(ImGui::ImageButton((void *)statusyellow, ImVec2(16, 16), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}}
			if(startup_shutdown_status_green){if(ImGui::ImageButton((void *)statusgreen, ImVec2(16, 16), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}}
			if (ImGui::IsItemHovered()){ImGui::BeginTooltip();ImGui::Text("Status - Click for details.");ImGui::EndTooltip();}
			ImGui::Separator();
			static int Automation_start = 1;
            ImGui::PushID(Automation_start);
			ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(0.2f, 2.0f, 0.6f));      
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(0.2f, 6.0f, 0.9f));
			ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(0.2f, 2.0f, 0.6f));
            ImGui::Button("Start##8");
            ImGui::PopStyleColor(3);
            ImGui::PopID();
            ImGui::SameLine();
            static int Automation_STOP = 1;
            ImGui::PushID(Automation_STOP);                 
            ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(4.0f, 0.3f, 0.7f));      
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(2.0f, 0.8f, 0.7f));
            ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(4.0f, 0.3f, 0.8f));
            ImGui::Button("Stop##8");
            ImGui::PopStyleColor(3);
            ImGui::PopID();	
            ImGui::SameLine();
            ImGui::Text("Automation");
			ImGui::SameLine(230);
            ImGui::SmallButton("?##8");
            if (ImGui::IsItemHovered()){ImGui::BeginTooltip();ImGui::Text(" Automatic reflexes\n\n Updates\n Server response to fail over");ImGui::EndTooltip();}
			ImGui::SameLine();
			if(ImGui::Button("Setup##8")){automation_setup=true;}
			ImGui::SameLine();
			if(automation_status_empty){if(ImGui::ImageButton((void *)statusempty, ImVec2(16, 16), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}}
			if(automation_status_red){if(ImGui::ImageButton((void *)statusred, ImVec2(16, 16), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}}
			if(automation_status_yellow){if(ImGui::ImageButton((void *)statusyellow, ImVec2(16, 16), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}}
			if(automation_status_green){if(ImGui::ImageButton((void *)statusgreen, ImVec2(16, 16), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}}
			if (ImGui::IsItemHovered()){ImGui::BeginTooltip();ImGui::Text("Status - Click for details.");ImGui::EndTooltip();}
			ImGui::Separator();
			static int Contribution_start = 1;
            ImGui::PushID(Contribution_start);
			ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(0.2f, 2.0f, 0.6f));      
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(0.2f, 6.0f, 0.9f));
			ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(0.2f, 2.0f, 0.6f));
            ImGui::Button("Start##9");
            ImGui::PopStyleColor(3);
            ImGui::PopID();
            ImGui::SameLine();
            static int Contribution_STOP = 1;
            ImGui::PushID(Contribution_STOP);                 
            ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(4.0f, 0.3f, 0.7f));      
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(2.0f, 0.8f, 0.7f));
            ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(4.0f, 0.3f, 0.8f));
            ImGui::Button("Stop##9");
            ImGui::PopStyleColor(3);
            ImGui::PopID();
            ImGui::SameLine();
            ImGui::Text("Contribution");
			ImGui::SameLine(230);
            ImGui::SmallButton("?##9");
            if (ImGui::IsItemHovered()){ImGui::BeginTooltip();ImGui::Text(" Inactive, activities\n\n Donate CPU cycle times\n Research help \n Hosting torrents");ImGui::EndTooltip();}
			ImGui::SameLine();
			if(ImGui::Button("Setup##9")){cycles_contribution_setup=true;}
			ImGui::SameLine();
			if(cycles_contribution_status_empty){if(ImGui::ImageButton((void *)statusempty, ImVec2(16, 16), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}}
			if(cycles_contribution_status_red){if(ImGui::ImageButton((void *)statusred, ImVec2(16, 16), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}}
			if(cycles_contribution_status_yellow){if(ImGui::ImageButton((void *)statusyellow, ImVec2(16, 16), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}}
			if(cycles_contribution_status_green){if(ImGui::ImageButton((void *)statusgreen, ImVec2(16, 16), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}}
			if (ImGui::IsItemHovered()){ImGui::BeginTooltip();ImGui::Text("Status - Click for details.");ImGui::EndTooltip();}
			ImGui::Separator();
			static int MySQL_DB_start = 1;
            ImGui::PushID(MySQL_DB_start);
			ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(0.2f, 2.0f, 0.6f));      
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(0.2f, 6.0f, 0.9f));
			ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(0.2f, 2.0f, 0.6f));
            ImGui::Button("Start##10");
            ImGui::PopStyleColor(3);
            ImGui::PopID();
            ImGui::SameLine();
            static int MySQL_DB_STOP = 1;
            ImGui::PushID(MySQL_DB_STOP);                 
            ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(4.0f, 0.3f, 0.7f));      
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(2.0f, 0.8f, 0.7f));
            ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(4.0f, 0.3f, 0.8f));
            ImGui::Button("Stop##10");
            ImGui::PopStyleColor(3);
            ImGui::PopID();
            ImGui::SameLine();
            ImGui::Text("MySQL DB");
			ImGui::SameLine(230);
            ImGui::SmallButton("?##10");
            if (ImGui::IsItemHovered()){ImGui::BeginTooltip();ImGui::Text(" MySQL Database management\n\n New\n Add\n Remove\n Change");ImGui::EndTooltip();}
			ImGui::SameLine();
			if(ImGui::Button("Setup##10")){mysql_database_custom_setup=true;}
			ImGui::SameLine();
			if(mysql_database_custom_status_empty){if(ImGui::ImageButton((void *)statusempty, ImVec2(16, 16), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}}
			if(mysql_database_custom_status_red){if(ImGui::ImageButton((void *)statusred, ImVec2(16, 16), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}}
			if(mysql_database_custom_status_yellow){if(ImGui::ImageButton((void *)statusyellow, ImVec2(16, 16), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}}
			if(mysql_database_custom_status_green){if(ImGui::ImageButton((void *)statusgreen, ImVec2(16, 16), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}}
			if (ImGui::IsItemHovered()){ImGui::BeginTooltip();ImGui::Text("Status - Click for details.");ImGui::EndTooltip();}
			ImGui::Separator();
			static int Date_and_Time_start = 1;
            ImGui::PushID(Date_and_Time_start);
			ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(0.2f, 2.0f, 0.6f));      
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(0.2f, 6.0f, 0.9f));
			ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(0.2f, 2.0f, 0.6f));
           	if(ImGui::Button("Start##11")){boost::thread_group threads;threads.create_thread(daytime_server_start);}
           	ImGui::PopStyleColor(3);
            ImGui::PopID();
            ImGui::SameLine();
            static int Date_and_Time_STOP = 1;
            ImGui::PushID(Date_and_Time_STOP);                 
            ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(4.0f, 0.3f, 0.7f));      
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(2.0f, 0.8f, 0.7f));
            ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(4.0f, 0.3f, 0.8f));
            ImGui::Button("Stop##11");
            ImGui::PopStyleColor(3);
            ImGui::PopID();	
            ImGui::SameLine();
            ImGui::Text("Date & Time");
			ImGui::SameLine(230);
            ImGui::SmallButton("?##11");
            if (ImGui::IsItemHovered()){ImGui::BeginTooltip();ImGui::Text(" Date and time server\n\n Client request for server date & time");ImGui::EndTooltip();}
			ImGui::SameLine();
			if(ImGui::Button("Setup##11")){date_time_server_setup=true;}
			ImGui::SameLine();
			if(date_time_server_status_empty){if(ImGui::ImageButton((void *)statusempty, ImVec2(16, 16), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}}
			if(date_time_server_status_red){if(ImGui::ImageButton((void *)statusred, ImVec2(16, 16), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}}
			if(date_time_server_status_yellow){if(ImGui::ImageButton((void *)statusyellow, ImVec2(16, 16), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}}
			if(date_time_server_status_green){if(ImGui::ImageButton((void *)statusgreen, ImVec2(16, 16), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}}
			if (ImGui::IsItemHovered()){ImGui::BeginTooltip();ImGui::Text("Status - Click for details.");ImGui::EndTooltip();}
			ImGui::Separator();
			static int Bandwidth_usage_start = 1;
            ImGui::PushID(Bandwidth_usage_start);
			ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(0.2f, 2.0f, 0.6f));      
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(0.2f, 6.0f, 0.9f));
			ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(0.2f, 2.0f, 0.6f));
            ImGui::Button("Start##12");
            ImGui::PopStyleColor(3);
            ImGui::PopID();
            ImGui::SameLine();
            static int Bandwidth_usage_STOP = 1;
            ImGui::PushID(Bandwidth_usage_STOP);                 
            ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(4.0f, 0.3f, 0.7f));      
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(2.0f, 0.8f, 0.7f));
            ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(4.0f, 0.3f, 0.8f));
            ImGui::Button("Stop##12");
            ImGui::PopStyleColor(3);
            ImGui::PopID();	
            ImGui::SameLine();
            ImGui::Text("Bandwidth usage");
			ImGui::SameLine(230);
            ImGui::SmallButton("?##12");
            if (ImGui::IsItemHovered()){ImGui::BeginTooltip();ImGui::Text(" Bandwidth monitor\n\n Upstream\n Downstream\n Limits & caps");ImGui::EndTooltip();}
			ImGui::SameLine();
			if(ImGui::Button("Setup##12")){bandwidth_monitor_setup=true;}
			ImGui::SameLine();
			if(bandwidth_monitor_status_empty){if(ImGui::ImageButton((void *)statusempty, ImVec2(16, 16), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}}
			if(bandwidth_monitor_status_red){if(ImGui::ImageButton((void *)statusred, ImVec2(16, 16), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}}
			if(bandwidth_monitor_status_yellow){if(ImGui::ImageButton((void *)statusyellow, ImVec2(16, 16), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}}
			if(bandwidth_monitor_status_green){if(ImGui::ImageButton((void *)statusgreen, ImVec2(16, 16), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}}
			if (ImGui::IsItemHovered()){ImGui::BeginTooltip();ImGui::Text("Status - Click for details.");ImGui::EndTooltip();}
			ImGui::Separator();
			static int IoT_Devices_start = 1;
            ImGui::PushID(IoT_Devices_start);
			ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(0.2f, 2.0f, 0.6f));      
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(0.2f, 6.0f, 0.9f));
			ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(0.2f, 2.0f, 0.6f));
            ImGui::Button("Start##13");
            ImGui::PopStyleColor(3);
            ImGui::PopID();
            ImGui::SameLine();
            static int IoT_Devices_STOP = 1;
            ImGui::PushID(IoT_Devices_STOP);                 
            ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(4.0f, 0.3f, 0.7f));      
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(2.0f, 0.8f, 0.7f));
            ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(4.0f, 0.3f, 0.8f));
            ImGui::Button("Stop##13");
            ImGui::PopStyleColor(3);
            ImGui::PopID();
            ImGui::SameLine();
            ImGui::Text("IoT Devices");
			ImGui::SameLine(230);
            ImGui::SmallButton("?##13");
            if (ImGui::IsItemHovered()){ImGui::BeginTooltip();ImGui::Text(" Internet of Things Devices\n\n Connectivity\n storage\n Setup");ImGui::EndTooltip();}
			ImGui::SameLine();
			if(ImGui::Button("Setup##13")){IoT_device_relay_or_storage_setup=true;}
			ImGui::SameLine();
			if(IoT_device_relay_or_storage_status_empty){if(ImGui::ImageButton((void *)statusempty, ImVec2(16, 16), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}}
			if(IoT_device_relay_or_storage_status_red){if(ImGui::ImageButton((void *)statusred, ImVec2(16, 16), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}}
			if(IoT_device_relay_or_storage_status_yellow){if(ImGui::ImageButton((void *)statusyellow, ImVec2(16, 16), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}}
			if(IoT_device_relay_or_storage_status_green){if(ImGui::ImageButton((void *)statusgreen, ImVec2(16, 16), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}}
			if (ImGui::IsItemHovered()){ImGui::BeginTooltip();ImGui::Text("Status - Click for details.");ImGui::EndTooltip();}
			ImGui::Separator();
			static int Local_network_start = 1;
            ImGui::PushID(Local_network_start);
			ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(0.2f, 2.0f, 0.6f));      
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(0.2f, 6.0f, 0.9f));
			ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(0.2f, 2.0f, 0.6f));
            ImGui::Button("Start##14");
            ImGui::PopStyleColor(3);
            ImGui::PopID();
            ImGui::SameLine();
            static int Local_network_STOP = 1;
            ImGui::PushID(Local_network_STOP);                 
            ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(4.0f, 0.3f, 0.7f));      
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(2.0f, 0.8f, 0.7f));
            ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(4.0f, 0.3f, 0.8f));
            ImGui::Button("Stop##14");
            ImGui::PopStyleColor(3);
            ImGui::PopID();
            ImGui::SameLine();
            ImGui::Text("Local network");
			ImGui::SameLine(230);
            ImGui::SmallButton("?##14");
            if (ImGui::IsItemHovered()){ImGui::BeginTooltip();ImGui::Text(" Local network settings\n\n Intranet\n File sharing\n Streaming services");ImGui::EndTooltip();}
			ImGui::SameLine();
			if(ImGui::Button("Setup##14")){local_area_network_setup=true;}
			ImGui::SameLine();
			if(local_area_network_status_empty){if(ImGui::ImageButton((void *)statusempty, ImVec2(16, 16), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}}
			if(local_area_network_status_red){if(ImGui::ImageButton((void *)statusred, ImVec2(16, 16), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}}
			if(local_area_network_status_yellow){if(ImGui::ImageButton((void *)statusyellow, ImVec2(16, 16), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}}
			if(local_area_network_status_green){if(ImGui::ImageButton((void *)statusgreen, ImVec2(16, 16), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}}
			if (ImGui::IsItemHovered()){ImGui::BeginTooltip();ImGui::Text("Status - Click for details.");ImGui::EndTooltip();}
			ImGui::Separator();
			static int Ret_Dec_Services_start = 1;
            ImGui::PushID(Ret_Dec_Services_start);
			ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(0.2f, 2.0f, 0.6f));      
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(0.2f, 6.0f, 0.9f));
			ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(0.2f, 2.0f, 0.6f));
            ImGui::Button("Start##15");
            ImGui::PopStyleColor(3);
            ImGui::PopID();
            ImGui::SameLine();
            static int Ret_Dec_Services_STOP = 1;
            ImGui::PushID(Ret_Dec_Services_STOP);                 
            ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(4.0f, 0.3f, 0.7f));      
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(2.0f, 0.8f, 0.7f));
            ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(4.0f, 0.3f, 0.8f));
            ImGui::Button("Stop##15");
            ImGui::PopStyleColor(3);
            ImGui::PopID();	
            ImGui::SameLine();
            ImGui::Text("Ret-Dec Services");
			ImGui::SameLine(230);
            ImGui::SmallButton("?##15");
            if (ImGui::IsItemHovered()){ImGui::BeginTooltip();ImGui::Text(" Retargetable decompiler\n\n Settings\n Current process\n Statistics");ImGui::EndTooltip();}
			ImGui::SameLine();
			if(ImGui::Button("Setup##15")){retargetable_decompiler_setup=true;}
			ImGui::SameLine();
			if(retargetable_decompiler_status_empty){if(ImGui::ImageButton((void *)statusempty, ImVec2(16, 16), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}}
			if(retargetable_decompiler_status_red){if(ImGui::ImageButton((void *)statusred, ImVec2(16, 16), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}}
			if(retargetable_decompiler_status_yellow){if(ImGui::ImageButton((void *)statusyellow, ImVec2(16, 16), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}}
			if(retargetable_decompiler_status_green){if(ImGui::ImageButton((void *)statusgreen, ImVec2(16, 16), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}}
			if (ImGui::IsItemHovered()){ImGui::BeginTooltip();ImGui::Text("Status - Click for details.");ImGui::EndTooltip();}
			ImGui::Separator();
//			ImGui::Checkbox("S2S Services    ",&s2s_server_services);
//			ImGui::SameLine();
//          ImGui::SmallButton("?##16");
//          if (ImGui::IsItemHovered()){ImGui::BeginTooltip();ImGui::Text(" Server to server connectivity\n\n Discover mode\n Settings\n S2S tools");ImGui::EndTooltip();}
//			ImGui::SameLine();
//			if(ImGui::Button("Setup##16")){s2s_server_services_setup=true;}
//			ImGui::SameLine();
//			if(s2s_server_services_status_empty){if(ImGui::ImageButton((void *)statusempty, ImVec2(16, 16), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}}
//			if(s2s_server_services_status_red){if(ImGui::ImageButton((void *)statusred, ImVec2(16, 16), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}}
//			if(s2s_server_services_status_yellow){if(ImGui::ImageButton((void *)statusyellow, ImVec2(16, 16), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}}
//			if(s2s_server_services_status_green){if(ImGui::ImageButton((void *)statusgreen, ImVec2(16, 16), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}}
//			if (ImGui::IsItemHovered()){ImGui::BeginTooltip();ImGui::Text("Status - Click for details.");ImGui::EndTooltip();}
//			ImGui::Separator();
			if(ImGui::Button("TCP::IP -I"))
			{
				static ImGuiOnceUponAFrame Ipstatus;	
				if (Ipstatus)
					{
						boost::thread_group threads;
						threads.create_thread(ipconfigure);
					}
			}
			ImGui::SameLine(125);
			if(ImGui::Button("Netstat ON"))
			{
				static ImGuiOnceUponAFrame Ipstatus;	
				if (Ipstatus)
					{
						boost::thread_group threads;
						threads.create_thread(ipconfigure_netstat_on);
					}
			}
			ImGui::SameLine(240);
			if(ImGui::Button("Netstat -A"))
			{
				static ImGuiOnceUponAFrame Ipstatus;	
				if (Ipstatus)
					{
						boost::thread_group threads;
						threads.create_thread(ipconfigure_netstat_a);
					}
			}
			
			if(ImGui::Button("Netstat -O"))
			{
				static ImGuiOnceUponAFrame Ipstatus;	
				if (Ipstatus)
					{
						boost::thread_group threads;
						threads.create_thread(ipconfigure_netstat_o);
					}
			}
			ImGui::SameLine(125);
			if(ImGui::Button("Netstat -T"))
			{
				static ImGuiOnceUponAFrame Ipstatus;	
				if (Ipstatus)
					{
						boost::thread_group threads;
						threads.create_thread(ipconfigure_netstat_t);
					}
			}
			ImGui::SameLine(240);
			if(ImGui::Button("Netstat -F"))
			{
				static ImGuiOnceUponAFrame Ipstatus;	
				if (Ipstatus)
					{
						boost::thread_group threads;
						threads.create_thread(ipconfigure_netstat_f);
					}
			}
			ImGui::PopItemWidth();
			ImGui::EndChild();
			
			
			ImGui::BeginChild("####start_web_server", ImVec2(300,60), true,ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);
            
			ImGui::SameLine();
			if(ImGui::ImageButton((void *)resume, ImVec2(20, 20), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255)))
			{
				boost::thread_group threads;
				threads.create_thread(ImGui_web_server_start);
			}
        	if (ImGui::IsItemHovered()){ImGui::BeginTooltip();ImGui::Text("Start");ImGui::EndTooltip();}
			ImGui::SameLine();
			if(ImGui::ImageButton((void *)pause, ImVec2(20, 20), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}
	        if (ImGui::IsItemHovered()){ImGui::BeginTooltip();ImGui::Text("Pause");ImGui::EndTooltip();}
			
			ImGui::SameLine();
			if(ImGui::ImageButton((void *)stop, ImVec2(20, 20), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}
	        if (ImGui::IsItemHovered()){ImGui::BeginTooltip();ImGui::Text("Stop");ImGui::EndTooltip();}
			
			ImGui::SameLine();
			if(web_status_empty){if(ImGui::ImageButton((void *)statusempty, ImVec2(20, 20), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}}
			if(web_status_red){if(ImGui::ImageButton((void *)statusred, ImVec2(20, 20), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}}
			if(web_status_yellow){if(ImGui::ImageButton((void *)statusyellow, ImVec2(20, 20), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}}
			if(web_status_green){if(ImGui::ImageButton((void *)statusgreen, ImVec2(20, 20), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}}
			if (ImGui::IsItemHovered()){ImGui::BeginTooltip();ImGui::Text("Status - Click for details.");ImGui::EndTooltip();}

			ImGui::EndChild();
			
            ImGui::SameLine();
			ImGui::BeginChild("####start_ftp_server", ImVec2(300,60), true,ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);
            
			if(ImGui::ImageButton((void *)resume, ImVec2(20, 20), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}
	        if (ImGui::IsItemHovered()){ImGui::BeginTooltip();ImGui::Text("Start");ImGui::EndTooltip();}
				
			ImGui::SameLine();
			if(ImGui::ImageButton((void *)pause, ImVec2(20, 20), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}
	        if (ImGui::IsItemHovered()){ImGui::BeginTooltip();ImGui::Text("Pause");ImGui::EndTooltip();}
			
			ImGui::SameLine();
			if(ImGui::ImageButton((void *)stop, ImVec2(20, 20), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}
	        if (ImGui::IsItemHovered()){ImGui::BeginTooltip();ImGui::Text("Stop");ImGui::EndTooltip();}
			
			ImGui::SameLine();
			if(ftp_status_empty){if(ImGui::ImageButton((void *)statusempty, ImVec2(20, 20), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}}
			if(ftp_status_red){if(ImGui::ImageButton((void *)statusred, ImVec2(20, 20), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}}
			if(ftp_status_yellow){if(ImGui::ImageButton((void *)statusyellow, ImVec2(20, 20), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}}
			if(ftp_status_green){if(ImGui::ImageButton((void *)statusgreen, ImVec2(20, 20), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}}
			if (ImGui::IsItemHovered()){ImGui::BeginTooltip();ImGui::Text("Status - Click for details.");ImGui::EndTooltip();}

			ImGui::EndChild();
			
			ImGui::SameLine();
			ImGui::BeginChild("####Network_tools_Running_info", ImVec2(340,60), true,ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);
            static int LIVE = 1;
            ImGui::PushID(LIVE);
			ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(0.2f, 2.0f, 0.6f));      
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(0.2f, 6.0f, 0.9f));
            ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(0.2f, 2.0f, 0.6f));
            if(ImGui::Button("Active file transfers")){active_file_transfers=true;}
            ImGui::SameLine(200);
            if(ImGui::Button("Web page requests")){Web_page_hits=true;}
            if(ImGui::Button("Server uptime display")){all_services_uptime=true;}
			ImGui::PopStyleColor(3);
            ImGui::PopID();
			ImGui::SameLine(200);
			static int STOP = 1;
            ImGui::PushID(STOP);                 
            ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(4.0f, 0.3f, 0.7f));      
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(2.0f, 0.8f, 0.7f));
            ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(4.0f, 0.3f, 0.8f));
            if(ImGui::Button("Stop All services")){stop_all_services=true;}
			ImGui::PopStyleColor(3);
            ImGui::PopID();
			ImGui::EndChild();
			ImGui::PopStyleVar();
            ImGui::End();
		}
//////////////////////////////////////////////////////////////////
//
//	Settings windows
//
		if(show_HTTP_settings)
		{
			ImGui::Begin("HTTP advanced settings", &show_HTTP_settings);
			
			ImGui::End();
		}
		if(show_FTP_settings)
		{
			ImGui::Begin("FTP advanced settings", &show_FTP_settings);
			ImGui::End();
		}
		if(show_FTP_white_list)
		{
			ImGui::Begin("FTP White list", &show_FTP_white_list);
			ImGui::End();
		}
		if(show_FTP_permissions)
		{
			ImGui::Begin("FTP Permissions", &show_FTP_permissions);
			ImGui::End();
		}
		if(show_network_tools_admin)
		{
			ImGui::Begin("Administrative tools", &show_network_tools_admin);
			ImGui::End();
		}
		if(show_network_tools_logging)
		{
			ImGui::Begin("Network tools IP logging", &show_network_tools_logging);
			ImGui::End();
		}
		if(show_network_tools_blocked)
		{
			ImGui::Begin("Network tools IPs blocked", &show_network_tools_blocked);
			ImGui::End();
		}
		if(show_network_tools_FTP_log)
		{
			ImGui::Begin("Network tools FTP log & events", &show_network_tools_FTP_log);
			ImGui::End();
		}
		if(Dummytraffic_setup)
		{
			ImGui::Begin("Dummy traffic setup", &Dummytraffic_setup);
			ImGui::End();
		}
		if(echo_allowed_setup)
		{
			ImGui::Begin("Echo setup", &echo_allowed_setup);
			ImGui::Text("");
			ImGui::Text("Echo server settings:");
			ImGui::Separator();
			ImGui::Text("Port");
			ImGui::InputText("###echo_port_select", echo_server_port, IM_ARRAYSIZE(echo_server_port), ImGuiInputTextFlags_CharsNoBlank | ImGuiInputTextFlags_AutoSelectAll);
			ImGui::Separator();
			ImGui::Text("Launch echo client:");
			if(ImGui::Button("Echo test")){boost::thread_group threads;threads.create_thread(echo_client_test);}
			ImGui::Separator();
			ImGui::Text("");
			ImGui::End();
		}
		if(enable_chat_setup)
		{
			ImGui::Begin("IRC setup", &enable_chat_setup);
			ImGui::End();
		}
		if(team_speak_setup)
		{
			ImGui::Begin("Teamspeak setup", &team_speak_setup);
			ImGui::End();
		}
		if(log_to_other_setup)
		{
			ImGui::Begin("Log forwarding setup", &log_to_other_setup);
			ImGui::End();
		}
		if(startup_shutdown_setup)
		{
			ImGui::Begin("Remote commands setup", &startup_shutdown_setup);
			ImGui::End();
		}
		if(automation_setup)
		{
			ImGui::Begin("Automation setup", &automation_setup);
			ImGui::End();
		}
		if(cycles_contribution_setup)
		{
			ImGui::Begin("Donations setup", &cycles_contribution_setup);
			ImGui::End();
		}
		if(preventative_maintenance_setup)
		{
			ImGui::Begin("Preventative maintenance setup", &preventative_maintenance_setup);
			ImGui::End();
		}
		if(mysql_database_custom_setup)
		{
			ImGui::Begin("MySQL custom databases setup", &mysql_database_custom_setup);
			ImGui::End();
		}
		if(mysql_database_custom_setup)
		{
			ImGui::Begin("MySQL custom databases setup", &mysql_database_custom_setup);
			ImGui::End();
		}
		if(date_time_server_setup)
		{
			ImGui::Begin("Date and time server setup", &date_time_server_setup);
			ImGui::Text("");
			ImGui::Text("Date and time test client:");
			if(ImGui::Button("Client start")){boost::thread_group threads;threads.create_thread(Date_time_client_start);}
			ImGui::Separator();
			ImGui::End();
		}
		if(bandwidth_monitor_setup)
		{
			ImGui::Begin("Bandwidth monitor setup", &bandwidth_monitor_setup);
			ImGui::End();
		}
		if(IoT_device_relay_or_storage_setup)
		{
			ImGui::Begin("Internet of Things setup", &IoT_device_relay_or_storage_setup);
			ImGui::End();
		}
		if(local_area_network_setup)
		{
			ImGui::Begin("LAN settings", &local_area_network_setup);
			ImGui::End();
		}
		if(retargetable_decompiler_setup)
		{
			ImGui::Begin("Retargetable decompiler setup", &retargetable_decompiler_setup);
			ImGui::End();
		}
		if(s2s_server_services_setup)
		{
			ImGui::Begin("Server to server tools & services", &s2s_server_services_setup);
			ImGui::End();	
		}
/////////////////////////////////////////////////////////////////
//
// Help calls
//
		if(show_web_help)
		{
			ImGui::Begin("Web server help", &show_web_help);
			ImGui::Text("");
			ImGui::Text("Web server information:\n\n"
						"Usage & default settings:\n\n"
						"Clicking the start button (play icon) beneath the web server setup.\n"
						"With default settings IP 127.0.0.1 PORT 80 will start a \"loop-back address\"\n"
						"Typing 127.0.0.1 into a web browser (Internet explorer) with the web server started and is0bel server running.\n"
						"Will display \"Home.html\" webpage. This is so you can have the client and server on the same machine for testing.\n\n"
						"Actual internet face setup:\n\n"
						"The programs heart IS a server and with port forwarding enabled from the router with static IP can be used as such.\n"
						"This program is not for the technically inept.\n\n"
						"Setup as follows:");
			ImGui::End();
		}
		
		if(show_ftp_help)
		{
			ImGui::Begin("FTP server help", &show_ftp_help);
			ImGui::Text("");
			ImGui::Text("FTP server information:\n\n"
						"Usage & default settings:\n\n"
						"Clicking the start button (play icon) beneath the FTP server setup.\n"
						"With default settings IP 127.0.0.2 PORT 2020 will start a \"loop-back address\"\n"
						"Typing 127.0.0.`:2020 into a FTP program with the FTP server started and is0bel server running.\n"
						"Will display the FTP index folder. This is so you can have the client and server on the same machine for testing.\n\n"
						"Actual internet face setup:\n\n"
						"The programs heart IS a server and with port forwarding enabled from the router with static IP can be used as such.\n"
						"This program is not for the technically inept.\n\n"
						"Setup as follows:");
			ImGui::End();
		}
		
		if(show_network_tools_help)
		{
			ImGui::Begin("FTP server help", &show_network_tools_help);
			ImGui::Text("");
			ImGui::Text("Server side tools tools:");
			ImGui::Text("");
			ImGui::Text("");
			ImGui::Text("-Administrative");ImGui::SameLine(200);ImGui::Text("-- Admin password and screen lock and next program start password required.");
			ImGui::Text("-Web browser");ImGui::SameLine(200);ImGui::Text("-- For browsing or loop back testing.");
			ImGui::Text("-Logging");ImGui::SameLine(200);ImGui::Text("-- All tcp/udp/ip packets sent to the Is0bel server with source location if possible.");
			ImGui::Text("-Blocked");ImGui::SameLine(200);ImGui::Text("-- Block all repeat offenders from accessing content from the server.");
			ImGui::Text("-Activities FTP/L");ImGui::SameLine(200);ImGui::Text("-- Logs all attempts at login and monitors all file activities.");
			ImGui::Text("");
			ImGui::Text("This is not a toy program, do not click a start button until setup complete.");
			ImGui::Text("Clicking a start button will start or enable a service.");
			ImGui::End();
			
		}
//////////////////////////////////////////////////////////////////
//
//	All services.
//
		if (stop_all_services)
		ImGui::OpenPopup("         Warning: STOP ALL?");
        if (ImGui::BeginPopupModal("         Warning: STOP ALL?", NULL, ImGuiWindowFlags_AlwaysAutoResize))
            {
				ImGui::PushItemWidth(248);
				if (ImGui::Button("Confirm",  ImVec2(120,0))) { ImGui::CloseCurrentPopup(); stop_all_services = false; }
                ImGui::SameLine();
                if (ImGui::Button("Cancel", ImVec2(120,0))) { ImGui::CloseCurrentPopup(); stop_all_services = false; }
                ImGui::PopItemWidth();
				ImGui::EndPopup();
            }
    	if(active_file_transfers)
		{
			ImGui::Begin("Active file transfers", &active_file_transfers);
			ImGui::End();
		}
    	if(Web_page_hits)
		{
			ImGui::Begin("Web page requests", &Web_page_hits);
			ImGui::End();
		}
    	if(all_services_uptime)
		{
			ImGui::Begin("All services uptime", &all_services_uptime);
			ImGui::End();
		}
/////////////////////////////////////////////////////////////
//
//	Still WIP, will be using LUA.editor browser for testing
//	
//	Calls to be added to browser.
//
//void ipconfigure_wmic() 
//{
//system("ipconfigure.wmic.bat");
//}
//void ipconfigure_wmic_help() 
//{
//system("ipconfigure.wmic.help.bat");
//}	
//
//		
		if (show_web_browser)
		{
			
			ImGui::Begin("WIP *Skeleton* Minimal web browser", &show_web_browser);
			ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 5.0f);
            ImGui::BeginChild("####webmenu", ImVec2(-1,35), true,ImGuiWindowFlags_NoScrollbar);
            
			if(ImGui::ImageButton((void *)home, ImVec2(20, 20), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}
            if (ImGui::IsItemHovered()){ImGui::BeginTooltip();ImGui::Text("Home");ImGui::EndTooltip();}
			
			ImGui::SameLine();
			if(ImGui::ImageButton((void *)back, ImVec2(20, 20), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}
            if (ImGui::IsItemHovered()){ImGui::BeginTooltip();ImGui::Text("Back");ImGui::EndTooltip();}
			
			ImGui::SameLine();
			if(ImGui::ImageButton((void *)stop, ImVec2(20, 20), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}
            if (ImGui::IsItemHovered()){ImGui::BeginTooltip();ImGui::Text("Stop");ImGui::EndTooltip();}
			
			ImGui::SameLine();
			if(ImGui::ImageButton((void *)forward, ImVec2(20, 20), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}
            if (ImGui::IsItemHovered()){ImGui::BeginTooltip();ImGui::Text("Forward");ImGui::EndTooltip();}
			
			ImGui::SameLine();
			ImGui::PushItemWidth(300);
			static char web_url[40] = "www.google.com";
			ImGui::InputText("###url_address", web_url, IM_ARRAYSIZE(web_url), ImGuiInputTextFlags_CharsNoBlank | ImGuiInputTextFlags_AutoSelectAll | ImGuiInputTextFlags_EnterReturnsTrue);
			ImGui::PopItemWidth();
			
			ImGui::SameLine();
			if(ImGui::ImageButton((void *)web, ImVec2(20, 20), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}
            if (ImGui::IsItemHovered()){ImGui::BeginTooltip();ImGui::Text("Go/Refresh");ImGui::EndTooltip();}
			
			
			ImGui::SameLine();
			if(ImGui::ImageButton((void *)bookmarks, ImVec2(20, 20), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){show_bookmarks_saved = true;}
            if (ImGui::IsItemHovered()){ImGui::BeginTooltip();ImGui::Text("Bookmarks");ImGui::EndTooltip();}
			
			ImGui::SameLine();
			if(ImGui::ImageButton((void *)downloads, ImVec2(20, 20), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){show_download_manager = true;}
            if (ImGui::IsItemHovered()){ImGui::BeginTooltip();ImGui::Text("Downloads & Uploads");ImGui::EndTooltip();}
			
			ImGui::SameLine();
			if(ImGui::ImageButton((void *)settings, ImVec2(20, 20), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){show_web_settings = true;}
            if (ImGui::IsItemHovered()){ImGui::BeginTooltip();ImGui::Text("Browser settings");ImGui::EndTooltip();}
			
			
			ImGui::EndChild();
			
            ImGui::BeginChild("####web_page_display", ImVec2(-1,400), true,ImGuiWindowFlags_NoScrollbar);
            
			ImGui::EndChild();
			ImGui::Separator();
			char buf[128];
    		sprintf(buf, "Status : %c", "|/-\\"[(int)(ImGui::GetTime()/0.25f)&3], ImGui::GetFrameCount());
    		ImGui::Text(buf);
			ImGui::SameLine(ImGui::GetWindowContentRegionWidth()/2 +350);
			if(status_empty){if(ImGui::ImageButton((void *)statusempty, ImVec2(16, 16), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}}
			if(status_red){if(ImGui::ImageButton((void *)statusred, ImVec2(16, 16), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}}
			if(status_yellow){if(ImGui::ImageButton((void *)statusyellow, ImVec2(16, 16), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}}
			if(status_green){if(ImGui::ImageButton((void *)statusgreen, ImVec2(16, 16), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}}
			if (ImGui::IsItemHovered()){ImGui::BeginTooltip();ImGui::Text("Status - Click for details.");ImGui::EndTooltip();}
			
//////////////////////////////////////////////////////////
//
//	Used for tcp/ip checking connectivity.
//	Will be broken down and removed.
//	Useful for copy/paste.
//
//			
			if(status_empty){status_yellow = false;status_green = false;status_red = false;}
			if(status_red){status_yellow = false;status_green = false;status_empty = false;}
			if(status_yellow){status_red = false;status_green = false;status_empty = false;}
			if(status_green){status_yellow = false;status_red = false;status_empty = false;}

/////////////////////////////////////////////////////////
			
			ImGui::PopStyleVar();
			ImGui::End();
		}
		

if(show_web_settings)
		{
			ImGui::Begin("Browser settings", &show_web_settings, ImGuiWindowFlags_MenuBar);
				if (ImGui::BeginMenuBar())
				{
				if (ImGui::BeginMenu("Options"))
				{
		    		
		    		if (ImGui::MenuItem("  Save", NULL)){}
		    		if (ImGui::MenuItem("  Import", NULL)){}
		    		ImGui::MenuItem("  Export", NULL);
		    		ImGui::MenuItem("  Default", NULL);
					
		    		ImGui::EndMenu();
					}
				ImGui::EndMenuBar();
				}
			ImGui::Text("Settings for browser.\nClick on the headers for details.\nClick menu options to save.");
			ImGui::Text("");
//////////////////////////////////////////////////////////////
//
//	Helpful batch file calls.
//
			if (ImGui::CollapsingHeader("TCP/IP")) 
            {
			
			if(ImGui::Button("TCP::IP -I"))
			{
				static ImGuiOnceUponAFrame Ipstatus;	
				if (Ipstatus)
					{
						system("ipconfigure.bat");
					}
			}
			ImGui::SameLine();
			if(ImGui::Button("Netstat On"))
			{
				static ImGuiOnceUponAFrame Ipstatus;	
				if (Ipstatus)
					{
						system("ipconfigure.netstat.on.bat");
					}
			}
			ImGui::SameLine();
			if(ImGui::Button("Netstat -A"))
			{
				static ImGuiOnceUponAFrame Ipstatus;	
				if (Ipstatus)
					{
						system("ipconfigure.netstat.a.bat");
					}
			}
			
			if(ImGui::Button("Netstat -O"))
			{
				static ImGuiOnceUponAFrame Ipstatus;	
				if (Ipstatus)
					{
						system("ipconfigure.netstat.o.bat");
					}
			}
			ImGui::SameLine();
			if(ImGui::Button("Netstat -T"))
			{
				static ImGuiOnceUponAFrame Ipstatus;	
				if (Ipstatus)
					{
						system("ipconfigure.netstat.t.bat");
					}
			}
			ImGui::SameLine();
			if(ImGui::Button("Netstat -F"))
			{
				static ImGuiOnceUponAFrame Ipstatus;	
				if (Ipstatus)
					{
						system("ipconfigure.netstat.f.bat");
					}
			}
			}
			ImGui::Separator();
			if (ImGui::CollapsingHeader("WMIC")) 
			{
				
			if(ImGui::Button("WMIC Open"))
			{
				static ImGuiOnceUponAFrame Ipstatus1;	
				if (Ipstatus1)
					{
						system("ipconfigure.wmic.bat");
					}
			}
			ImGui::SameLine();
			if(ImGui::Button("WMIC - Support & Information"))
			{
				static ImGuiOnceUponAFrame Ipstatus;	
				if (Ipstatus)
					{
						system("ipconfigure.wmic.help.bat");
					}
			}
			}
////////////////////////////////////////////////////////////////
			ImGui::Separator();
			if (ImGui::CollapsingHeader("Browser options")) 
			{
			ImGui::Text("");	
			ImGui::Text("Mobile phone or Desktop browsing:");
			ImGui::Checkbox("Mobile only", &mobile_html);
			ImGui::Separator();
			ImGui::Text("Bookmarks:");
			ImGui::BeginChild("####bookmarks", ImVec2(-1,150), true,ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);
			ImGui::InputTextMultiline("##bookmarks_kept", bookmarks_kept, IM_ARRAYSIZE(bookmarks_kept), ImVec2(-1.0f, -1.0 * 16), ImGuiInputTextFlags_AllowTabInput);
			if(ImGui::SmallButton("Update bookmarks")){ofstream save_data("Bookmarks.setting");if (save_data.is_open()){save_data << bookmarks_kept;save_data.close(); show_save_complete = true;}}
			if (ImGui::IsItemHovered()){ImGui::BeginTooltip();ImGui::Text("Update to save bookmarks.");ImGui::EndTooltip();}
			ImGui::EndChild();
			ImGui::PushItemWidth(-1);
			ImGui::Separator();
			ImGui::Text("Homepage:");
			static char homepage[256] = "www.google.com";
			ImGui::InputText("###default_homepage", homepage, IM_ARRAYSIZE(homepage), ImGuiInputTextFlags_CharsNoBlank | ImGuiInputTextFlags_AutoSelectAll);
			ImGui::Separator();
			ImGui::Text("Downloads folder:");
			static char download_folder[256] = "C:\\";
			ImGui::InputText("###default_download", download_folder, IM_ARRAYSIZE(download_folder), ImGuiInputTextFlags_CharsNoBlank | ImGuiInputTextFlags_AutoSelectAll);
			ImGui::PopItemWidth();
			}
			
			ImGui::Separator();
			if (ImGui::CollapsingHeader("FTP")) 
            {
            ImGui::PushItemWidth(-1);
			ImGui::Text("");	
			ImGui::Text("FTP Settings:");
			ImGui::Text("");
			ImGui::Text("IP:PORT");
			static char ftpconnect[256] = "192.168.0.1:1000";
			ImGui::InputText("###default_ftpip", ftpconnect, IM_ARRAYSIZE(ftpconnect), ImGuiInputTextFlags_CharsNoBlank | ImGuiInputTextFlags_AutoSelectAll);
			ImGui::Text("");
			ImGui::Text("Login details:");
			static char ftp_connect_name[256] = "Username";
			ImGui::InputText("###default_ftp_name", ftp_connect_name, IM_ARRAYSIZE(ftp_connect_name), ImGuiInputTextFlags_CharsNoBlank | ImGuiInputTextFlags_AutoSelectAll);
			static char ftp_connect_password[256] = "Password";
			ImGui::InputText("###default_ftp_password", ftp_connect_password, IM_ARRAYSIZE(ftp_connect_password), ImGuiInputTextFlags_CharsNoBlank | ImGuiInputTextFlags_AutoSelectAll | ImGuiInputTextFlags_Password);
			ImGui::Checkbox("Save FTP Login credentials", &save_ftp_login);
			ImGui::Text("");
			ImGui::Text("FTP Connection test. ");
			ImGui::SameLine();
			ImGui::SmallButton("Test");
			ImGui::PopItemWidth();
			}
			ImGui::Separator();
			if (ImGui::CollapsingHeader("Cloud Settings")) 
			{
			ImGui::PushItemWidth(-1);	
			ImGui::Text("");	
			ImGui::Text("Cloud Settings:");
			ImGui::Text("");
			ImGui::Text("Web address:");
			static char cloudconnect[256] = "www.google.com/cloud";
			ImGui::InputText("###default_cloudaddress", cloudconnect, IM_ARRAYSIZE(cloudconnect), ImGuiInputTextFlags_CharsNoBlank | ImGuiInputTextFlags_AutoSelectAll);
			ImGui::Text("");
			ImGui::Text("Login details:");
			static char cloud_connect_name[256] = "Username";
			ImGui::InputText("###default_cloud_name", cloud_connect_name, IM_ARRAYSIZE(cloud_connect_name), ImGuiInputTextFlags_CharsNoBlank | ImGuiInputTextFlags_AutoSelectAll);
			static char cloud_connect_password[256] = "Password";
			ImGui::InputText("###default_cloud_password", cloud_connect_password, IM_ARRAYSIZE(cloud_connect_password), ImGuiInputTextFlags_CharsNoBlank | ImGuiInputTextFlags_AutoSelectAll | ImGuiInputTextFlags_Password);
			ImGui::Checkbox("Save Cloud Login credentials", &save_cloud_login);
			ImGui::Text("");
			ImGui::Text("Cloud Connection test. ");
			ImGui::SameLine();
			ImGui::SmallButton("Test");
			ImGui::PopItemWidth();
			}
			ImGui::Separator();
			ImGui::End();
		}
/////////////////////////////////////////////////////////////////
//
//	Downloads manager.
//
//	Handles upstream/downstream.
//
if (show_download_manager)
	{
		ImGui::Begin("Downloads & Uploads Manager", &show_download_manager);
		ImGui::Text("Download");
		ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 5.0f);
		ImGui::BeginChild("####Downloading", ImVec2(-1,135), true);
		ImGui::Text("Filename: ");
		ImGui::Separator();
		ImGui::Text("Host:");
		ImGui::Separator();
		static float Download_rate = 0.0f;
		ImGui::Text("Transfer:  %fKb/s",Download_rate);
		ImGui::Separator();
		static float Download = 0.0f;
		ImGui::ProgressBar(Download, ImVec2(-1.0f,0.0f));
		ImGui::Separator();
		if(ImGui::ImageButton((void *)resume, ImVec2(20, 20), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}
        if (ImGui::IsItemHovered()){ImGui::BeginTooltip();ImGui::Text("Continue");ImGui::EndTooltip();}
			
		ImGui::SameLine();
		if(ImGui::ImageButton((void *)pause, ImVec2(20, 20), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}
        if (ImGui::IsItemHovered()){ImGui::BeginTooltip();ImGui::Text("Pause");ImGui::EndTooltip();}
		
		ImGui::SameLine();
		if(ImGui::ImageButton((void *)stop, ImVec2(20, 20), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}
        if (ImGui::IsItemHovered()){ImGui::BeginTooltip();ImGui::Text("Cancel");ImGui::EndTooltip();}
		
		ImGui::SameLine();
		ImGui::Button("FTP Download");	
		
		ImGui::EndChild();
		ImGui::PopStyleVar();
		ImGui::Text("Upload");
		ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 5.0f);
		ImGui::BeginChild("####Uploading", ImVec2(-1,135), true);
		ImGui::Text("Filename: ");
		ImGui::Separator();
		ImGui::Text("Upload location:");
		ImGui::Separator();
		static float Upload_rate = 0.0f;
		ImGui::Text("Transfer:  %fKb/s",Upload_rate);
		ImGui::Separator();
		static float Upload = 0.0f;
		ImGui::ProgressBar(Upload, ImVec2(-1.0f,0.0f));
		ImGui::Separator();
		if(ImGui::ImageButton((void *)resume, ImVec2(20, 20), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}
        if (ImGui::IsItemHovered()){ImGui::BeginTooltip();ImGui::Text("Continue");ImGui::EndTooltip();}
			
		ImGui::SameLine();
		if(ImGui::ImageButton((void *)pause, ImVec2(20, 20), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}
        if (ImGui::IsItemHovered()){ImGui::BeginTooltip();ImGui::Text("Pause");ImGui::EndTooltip();}
		
		ImGui::SameLine();
		if(ImGui::ImageButton((void *)stop, ImVec2(20, 20), ImVec2(0,0),ImVec2(1,1),0,ImVec4(0,0,0,0),ImVec4(255,255,255,255))){}
        if (ImGui::IsItemHovered()){ImGui::BeginTooltip();ImGui::Text("Cancel");ImGui::EndTooltip();}
		
		ImGui::SameLine();
		ImGui::Button("FTP Upload");	
		
		ImGui::EndChild();
		ImGui::PopStyleVar();
		ImGui::End();
	}
//////////////////////////////////////////////////////////////
//
//	Bookmarks select.
//
//	Will used selected to seek.get(0,"url list location");
//	E.G :-
//
//	if seleced is left clicked
//	seek.get(0,i); https://github.com/ (1 from 0 - 2 - currently)
//
//	Load into buffer, pass buffer to resolver.
//	Bookmark page loaded, url in textinput changed
//	to reflect bookmark selected.
//
//	If selected is blank do nothing?.
//
if(show_bookmarks_saved)
	{
		
		ImGui::Begin("Bookmarks", &show_bookmarks_saved);
		char Bookmark_display[1024*16];
		ifstream file("Bookmarks.setting", ios::in|ios::ate);
			if (file.is_open())
				{						
				streampos size;			
		  		size = file.tellg();
				file.seekg (0, ios::beg);
				for (int w = 0; w < size; w++)
				{
				file.getline(Bookmark_display, size);	
				int i = -1;
				bool selected;
				char buf[32];
				sprintf(buf, "%s", Bookmark_display);
			    if (ImGui::Selectable(buf, selected == i)) 
				selected = i;
				}
				file.close();
				}
												
		ImGui::End();
	}
		
	if (show_save_complete)
		{
			ImGui::Begin("###saved", &show_save_complete);
			if(ImGui::Button("SAVED",ImVec2(-1,-1))) {show_save_complete = false;}
			ImGui::End();
		}	
		
		if (show_about_server)
		{	
			ImGui::Begin("About", &show_about_server);
            ImGui::Text("");
            ImGui::Text("Dear ImGui, %s", ImGui::GetVersion());
            ImGui::Text("By Omar Cornut and all dear imgui contributors.");
        	ImGui::Text("Dear ImGui is licensed under the MIT License, see LICENSE for more information.");
        	ImGui::Text("");
			ImGui::Text("Is0bel server by Luke Hays");
            ImGui::Text("");
			ImGui::Text("Written in C++, using Dev ++ with the TDM Mingw64 compiler.");
            ImGui::Text("Useing IMGUI API, Boost 1.67 library and MySQL++.");
            ImGui::Text("Wes built for testing tcp/ip programming.");
            ImGui::Text("Is0bel server incorporates everything i would need for a small personal Internet facing server.");
            ImGui::Text("Is0bel server was named after a gifted young women. =) The shadows will never be the same.");
            ImGui::End();
        }
		
		
		
		
		// Rendering
        ImGui::EndFrame();
        g_pd3dDevice->SetRenderState(D3DRS_ZENABLE, false);
        g_pd3dDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, false);
        g_pd3dDevice->SetRenderState(D3DRS_SCISSORTESTENABLE, false);
        D3DCOLOR clear_col_dx = D3DCOLOR_RGBA((int)(clear_color.x*255.0f), (int)(clear_color.y*255.0f), (int)(clear_color.z*255.0f), (int)(clear_color.w*255.0f));
        g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, clear_col_dx, 1.0f, 0);
        if (g_pd3dDevice->BeginScene() >= 0)
        {
            ImGui::Render();
            g_pd3dDevice->EndScene();
        }
        HRESULT result = g_pd3dDevice->Present(NULL, NULL, NULL, NULL);

        // Handle loss of D3D9 device
        if (result == D3DERR_DEVICELOST && g_pd3dDevice->TestCooperativeLevel() == D3DERR_DEVICENOTRESET)
        {
            ImGui_ImplDX9_InvalidateDeviceObjects();
            g_pd3dDevice->Reset(&g_d3dpp);
            ImGui_ImplDX9_CreateDeviceObjects();
        }
    }
	Shutdown:
    ImGui_ImplDX9_Shutdown();
    if (g_pd3dDevice) g_pd3dDevice->Release();
    if (pD3D) pD3D->Release();
    UnregisterClass(_T("ImGui Example"), wc.hInstance);

    return 0;
}


