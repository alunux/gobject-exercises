#ifndef MY_STUDENT_H
#define MY_STUDENT_H

#include <glib-object.h>

G_BEGIN_DECLS

#define MY_TYPE_STUDENT            (my_student_get_type())
#define MY_STUDENT(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), MY_TYPE_STUDENT, MyStudent))
#define MY_STUDENT_CONST(obj)      (G_TYPE_CHECK_INSTANCE_CAST ((obj), MY_TYPE_STUDENT, MyStudent const))
#define MY_STUDENT_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass),  MY_TYPE_STUDENT, MyStudentClass))
#define MY_IS_STUDENT(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), MY_TYPE_STUDENT))
#define MY_IS_STUDENT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass),  MY_TYPE_STUDENT))
#define MY_STUDENT_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj),  MY_TYPE_STUDENT, MyStudentClass))

typedef struct _MyStudent        MyStudent;
typedef struct _MyStudentClass   MyStudentClass;
typedef struct _MyStudentPrivate MyStudentPrivate;

struct _MyStudent
{
   GObject parent;

   /*< private >*/
   MyStudentPrivate *priv;
};

struct _MyStudentClass
{
   GObjectClass parent_class;
};

MyStudent   *my_student_new       (void);
GType        my_student_get_type  (void) G_GNUC_CONST;
const gchar *my_student_get_goals (MyStudent  *student);
void         my_student_set_goals (MyStudent  *student,
                                   const char *goals);
const gchar *my_student_get_name  (MyStudent  *student);
void         my_student_set_name  (MyStudent  *student,
                                   const char *name);

G_END_DECLS

#endif /* MY_STUDENT_H */
