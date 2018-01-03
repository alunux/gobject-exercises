#ifndef MY_STUDENT_H
#define MY_STUDENT_H

#include <glib-object.h>

G_BEGIN_DECLS

#define MY_TYPE_STUDENT (my_student_get_type())
G_DECLARE_FINAL_TYPE    (MyStudent, my_student, MY, STUDENT, GObject)

typedef struct _MyStudentPrivate MyStudentPrivate;

struct _MyStudent
{
	GObject parent;

	/*< private >*/
	MyStudentPrivate *priv;
};

MyStudent   *my_student_new            (void);
guint        my_student_get_chapter    (MyStudent   *student);
const gchar *my_student_get_experience (MyStudent   *student);
const gchar *my_student_get_first_name (MyStudent   *student);
const gchar *my_student_get_goals      (MyStudent   *student);
const gchar *my_student_get_last_name  (MyStudent   *student);
GTimeZone   *my_student_get_timezone   (MyStudent   *student);
void         my_student_set_chapter    (MyStudent   *student,
                                        guint        chapter);
void         my_student_set_experience (MyStudent   *student,
                                        const gchar *experience);
void         my_student_set_first_name (MyStudent   *student,
                                        const gchar *first_name);
void         my_student_set_goals      (MyStudent   *student,
                                        const gchar *goals);
void         my_student_set_last_name  (MyStudent   *student,
                                        const gchar *last_name);
void         my_student_set_timezone   (MyStudent   *student,
                                        GTimeZone   *timezone);

G_END_DECLS

#endif /* MY_STUDENT_H */
