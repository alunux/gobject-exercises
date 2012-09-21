#include <glib/gi18n.h>

#include "my-student.h"

G_DEFINE_TYPE(MyStudent, my_student, G_TYPE_OBJECT)

struct _MyStudentPrivate
{
   gchar *name;
   gchar *goals;
};

enum
{
   PROP_0,
   PROP_NAME,
   PROP_GOALS,
   LAST_PROP
};

static GParamSpec *gParamSpecs[LAST_PROP];

MyStudent *
my_student_new (void)
{
   return g_object_new(MY_TYPE_STUDENT, NULL);
}

/**
 * my_student_get_name:
 *
 */
const gchar *
my_student_get_name (MyStudent *student)
{
   g_return_val_if_fail(MY_IS_STUDENT(student), NULL);
   return student->priv->name;
}

/**
 * my_student_set_name:
 *
 */
void
my_student_set_name (MyStudent   *student,
                     const gchar *name)
{
   MyStudentPrivate *priv;

   g_return_if_fail(MY_IS_STUDENT(student));

   priv = student->priv;

   g_free(priv->name);
   priv->name = g_strdup(name);
   g_object_notify_by_pspec(G_OBJECT(student), gParamSpecs[PROP_NAME]);
}

/**
 * my_student_get_goals:
 *
 */
const gchar *
my_student_get_goals (MyStudent *student)
{
   g_return_val_if_fail(MY_IS_STUDENT(student), NULL);
   return student->priv->goals;
}

/**
 * my_student_set_goals:
 *
 */
void
my_student_set_goals (MyStudent   *student,
                      const gchar *goals)
{
   MyStudentPrivate *priv;

   g_return_if_fail(MY_IS_STUDENT(student));

   priv = student->priv;

   g_free(priv->goals);
   priv->goals = g_strdup(goals);
   g_object_notify_by_pspec(G_OBJECT(student), gParamSpecs[PROP_GOALS]);
}

static void
my_student_finalize (GObject *object)
{
   MyStudentPrivate *priv;

   priv = MY_STUDENT(object)->priv;

   g_free(priv->name);
   g_free(priv->goals);

   G_OBJECT_CLASS(my_student_parent_class)->finalize(object);
}

static void
my_student_get_property (GObject    *object,
                         guint       prop_id,
                         GValue     *value,
                         GParamSpec *pspec)
{
   MyStudent *student = MY_STUDENT(object);

   switch (prop_id) {
   case PROP_NAME:
      g_value_set_string(value, my_student_get_name(student));
      break;
   case PROP_GOALS:
      g_value_set_string(value, my_student_get_goals(student));
      break;
   default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, prop_id, pspec);
   }
}

static void
my_student_set_property (GObject      *object,
                         guint         prop_id,
                         const GValue *value,
                         GParamSpec   *pspec)
{
   MyStudent *student = MY_STUDENT(object);

   switch (prop_id) {
   case PROP_NAME:
      my_student_set_name(student, g_value_get_string(value));
      break;
   case PROP_GOALS:
      my_student_set_goals(student, g_value_get_string(value));
      break;
   default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, prop_id, pspec);
   }
}

static void
my_student_class_init (MyStudentClass *klass)
{
   GObjectClass *object_class;

   object_class = G_OBJECT_CLASS(klass);
   object_class->finalize = my_student_finalize;
   object_class->get_property = my_student_get_property;
   object_class->set_property = my_student_set_property;
   g_type_class_add_private(object_class, sizeof(MyStudentPrivate));

   /**
    * MyStudent:name:
    *
    */
   gParamSpecs[PROP_NAME] =
      g_param_spec_string("name",
                          _("Name"),
                          _("The students name."),
                          NULL,
                          G_PARAM_READWRITE);
   g_object_class_install_property(object_class, PROP_NAME,
                                   gParamSpecs[PROP_NAME]);

   /**
    * MyStudent:goals:
    *
    */
   gParamSpecs[PROP_GOALS] =
      g_param_spec_string("goals",
                          _("Goals"),
                          _("The students goals."),
                          NULL,
                          G_PARAM_READWRITE);
   g_object_class_install_property(object_class, PROP_GOALS,
                                   gParamSpecs[PROP_GOALS]);
}

static void
my_student_init (MyStudent *student)
{
   student->priv = G_TYPE_INSTANCE_GET_PRIVATE(student,
                                               MY_TYPE_STUDENT,
                                               MyStudentPrivate);
}
