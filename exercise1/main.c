#include "my-student.h"

static void
exercise1 (void)
{
   MyStudent *student;
   const gchar *name;
   const gchar *goals;

   student = my_student_new();
   my_student_set_name(student, "Student One");
   my_student_set_goals(student, "Learning GObject.");
   name = my_student_get_name(student);
   goals = my_student_get_goals(student);
   g_print("%s: %s\n", name, goals);
   g_object_unref(student);
}

static void
exercise2 (void)
{
   MyStudent *student;
   gchar *name;
   gchar *goals;

   student = g_object_new(MY_TYPE_STUDENT,
                          "name", "Student Two",
                          "goals", "Learning GObject More.",
                          NULL);
   g_object_get(student,
                "name", &name,
                "goals", &goals,
                NULL);
   g_print("%s: %s\n", name, goals);
   g_free(name);
   g_free(goals);
}

gint
main (gint   argc,
      gchar *argv[])
{
   g_type_init();
   exercise1();
   exercise2();
   return 0;
}
