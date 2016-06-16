#ifndef WL_APP_H
#define WL_APP_H

#include <gtk/gtk.h>

namespace WindowLib
{
	static GtkApplication app;
	
	static void Activate(GtkApplication *_app, gpointer _userData)
	{
		WindowLib::Window window();
		
		window.SetWidget(gtk_application_window_new(_app));
		gtk_window_set_title(GTK_WINDOW(window.GetWidget()), window.GetWidth(), window.GetLength());
		gtk_widget_show_all(window.GetWidget());
	}
	
	static void StartApp(int argc, char *argv[])
	{
		g_signal_connect(app, "Activate", G_CALLBACK(Activate), NULL);
		g_application_run (G_APPLICATION (app), argc, argv);
		g_object_unref(app);
	}
	
	static void CloseApp()
	{
		g_object_unref(app);
	}
};

#endif
