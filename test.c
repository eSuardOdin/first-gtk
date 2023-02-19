#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>

int count = 0;

void end_program (GtkWidget *wid, gpointer ptr) {
	gtk_main_quit ();
}

void count_button (GtkWidget *wid, gpointer ptr) {
	char buffer[30];
	count++;
	sprintf(buffer, "Button pressed %d times", count);
	gtk_label_set_text (GTK_LABEL (ptr), buffer);
}

int main (int argc, char *argv[]) {
/*
    printf("%d\n", argc);
    for (int i = 0; i < argc; i++) {
		printf("%s\n", argv[i]);
	}
*/
    gtk_init(&argc, &argv);
    GtkWidget *win = gtk_window_new (GTK_WINDOW_TOPLEVEL);                      // Creating window
    
    char btnName[255] = "Close window";
    GtkWidget *lbl = gtk_label_new ("My Label");
    GtkWidget *closeBtn = gtk_button_new_with_label (btnName);                  // Create a close btn
    GtkWidget *countBtn = gtk_button_new_with_label ("Add");                    // Count btn
    g_signal_connect (countBtn, "clicked", G_CALLBACK (count_button), lbl); 
    g_signal_connect (closeBtn, "clicked", G_CALLBACK (end_program), NULL);     // End program on btn click
    g_signal_connect (win, "delete_event", G_CALLBACK (end_program), NULL);     // End program on cross click
    
    
    
    GtkWidget *box = gtk_box_new (GTK_ORIENTATION_VERTICAL, 5);                 // https://docs.gtk.org/gtk3/class.Box.html
	gtk_box_pack_start (GTK_BOX (box), lbl, TRUE, TRUE, 0);				        // Append all to box
	gtk_box_pack_start (GTK_BOX (box), countBtn, TRUE, TRUE, 0);
	gtk_box_pack_start (GTK_BOX (box), closeBtn, TRUE, TRUE, 0);
    
    /*
    // Test args
    if(argc > 1) {
		for (int i = 1; i < argc; i++) {
		GtkWidget *lblI = gtk_label_new (argv[i]);
		gtk_box_pack_end (GTK_BOX (box), lblI, TRUE, TRUE, 0);
		}
	}
    */
    
    gtk_container_add (GTK_CONTAINER (win), box);                          // Append box to window
    
    gtk_widget_show_all (win);
    gtk_main ();
    return 0;
}
