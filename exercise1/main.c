#include "my-student.h"

gint
main (gint   argc,
	  gchar *argv[])
{
	MyStudent *student;
	GTimeZone *timezone;
	guint chapter;
	gchar *experience;
	gchar *first_name;
	gchar *goals;
	gchar *last_name;

	timezone = g_time_zone_new ("-0700");
	student = g_object_new (MY_TYPE_STUDENT,
							"chapter", 1,
							"experience", "Lot's of C, Python, C#.",
	                        "first-name", "Christian",
							"goals", "To enable as many as possible.",
	                        "last-name", "Hergert",
	                        "timezone", timezone,
	                        NULL);
	g_time_zone_unref (timezone);

	g_object_get (student,
	              "chapter", &chapter,
	              "experience", &experience,
	              "first-name", &first_name,
	              "goals", &goals,
	              "last-name", &last_name,
	              "timezone", &timezone,
	              NULL);

	g_print ("Using a copy of strings...\n"
	         "\n"
	         "      Name: %s %s\n"
             "   Chapter: %u\n"
			 "     Goals: %s\n"
			 "    Offset: %d\n"
			 "Experience: %s\n"
			 "\n",
			 first_name,
			 last_name,
			 chapter,
			 goals,
			 g_time_zone_get_offset (timezone, 0),
			 experience);

	g_free (experience);
	g_free (first_name);
	g_free (goals);
	g_free (last_name);
	g_time_zone_unref (timezone);

	g_print ("Using strings directly...\n"
	         "\n"
	         "      Name: %s %s\n"
             "   Chapter: %u\n"
			 "     Goals: %s\n"
			 "    Offset: %d\n"
			 "Experience: %s\n"
			 "\n",
			 my_student_get_first_name (student),
			 my_student_get_last_name (student),
			 my_student_get_chapter (student),
			 my_student_get_goals (student),
			 g_time_zone_get_offset (my_student_get_timezone (student), 0),
			 my_student_get_experience (student));

	g_object_unref (student);

	return 0;
}
