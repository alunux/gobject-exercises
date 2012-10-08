#include <glib/gi18n.h>

#include "my-student.h"

G_DEFINE_TYPE(MyStudent, my_student, G_TYPE_OBJECT)

struct _MyStudentPrivate
{
	guint      chapter;
	gchar     *experience;
	gchar     *first_name;
	gchar     *goals;
	gchar     *last_name;
	GTimeZone *timezone;
};

enum
{
	PROP_0,
	PROP_CHAPTER,
	PROP_EXPERIENCE,
	PROP_FIRST_NAME,
	PROP_GOALS,
	PROP_LAST_NAME,
	PROP_TIMEZONE,
	LAST_PROP
};

static GParamSpec *gParamSpecs[LAST_PROP];

/**
 * my_student_new:
 *
 * Create a new instance of #MyStudent.
 *
 * Returns: A new #MyStudent that should be freed with g_object_unref().
 */
MyStudent *
my_student_new (void)
{
	return g_object_new (MY_TYPE_STUDENT, NULL);
}

/**
 * my_student_get_chapter:
 * @student: (in): A #MyStudent.
 *
 * Fetches the "chapter" property which is the chapter the student is
 * currently working on.
 *
 * Returns: A #guint.
 */
guint
my_student_get_chapter (MyStudent *student)
{
	g_return_val_if_fail (MY_IS_STUDENT(student), 0);
	return student->priv->chapter;
}

/**
 * my_student_set_chapter:
 * @student: (in): A #MyStudent.
 * @chapter: (in): A #guint.
 *
 * Sets the "chapter" property which is the chapter the student is currently
 * working on.
 */
void
my_student_set_chapter (MyStudent *student,
						guint      chapter)
{
	g_return_if_fail(MY_IS_STUDENT(student));
	student->priv->chapter = chapter;
	g_object_notify_by_pspec (G_OBJECT (student),
	                          gParamSpecs[PROP_CHAPTER]);
}

/**
 * my_student_get_experience:
 * @student: (in): A #MyStudent.
 *
 * Fetches the "experience" property which is a string containing
 * the students experience.
 *
 * Returns: (transfer none): A string.
 */
const gchar *
my_student_get_experience (MyStudent *student)
{
	g_return_val_if_fail (MY_IS_STUDENT (student), NULL);
	return student->priv->experience;
}

/**
 * my_student_set_experience:
 * @student: (in): A #MyStudent.
 * @experience: (in) (allow-none): A string.
 *
 * Sets the "experience" property which is a string containing the
 * student's experience.
 */
void
my_student_set_experience (MyStudent   *student,
                           const gchar *experience)
{
	MyStudentPrivate *priv;

	g_return_if_fail (MY_IS_STUDENT (student));

	priv = student->priv;

	g_free (priv->experience);
	priv->experience = g_strdup (experience);
	g_object_notify_by_pspec (G_OBJECT (student),
	                          gParamSpecs[PROP_EXPERIENCE]);
}

/**
 * my_student_get_first_name:
 * @student: (in): A #MyStudent.
 *
 * Fetches the "first-name" property which is the first name of the student.
 *
 * Returns: (transfer none): A string.
 */
const gchar *
my_student_get_first_name (MyStudent *student)
{
	g_return_val_if_fail (MY_IS_STUDENT (student), NULL);
	return student->priv->first_name;
}

/**
 * my_student_set_first_name:
 * @student: (in): A #MyStudent.
 * @first_name: (in) (allow-none): A string.
 *
 * Sets the "first-name" property which is the first name of the student.
 */
void
my_student_set_first_name (MyStudent   *student,
                           const gchar *first_name)
{
	MyStudentPrivate *priv;

	g_return_if_fail (MY_IS_STUDENT (student));

	priv = student->priv;

	g_free (priv->first_name);
	priv->first_name = g_strdup (first_name);
	g_object_notify_by_pspec (G_OBJECT (student),
	                          gParamSpecs[PROP_FIRST_NAME]);
}

/**
 * my_student_get_goals:
 * @student: (in): A #MyStudent.
 *
 * Fetches the "goals" property which is a string containing the student's
 * goals.
 *
 * Returns: (transfer none): A string containing the users goals.
 */
const gchar *
my_student_get_goals (MyStudent *student)
{
	g_return_val_if_fail (MY_IS_STUDENT (student), NULL);
	return student->priv->goals;
}

/**
 * my_student_set_goals:
 * @student: (in): A #MyStudent.
 * @goals: (in) (allow-none): A string.
 *
 * Sets the "goals" property which is a string containing the goals of a
 * student.
 */
void
my_student_set_goals (MyStudent   *student,
                      const gchar *goals)
{
	MyStudentPrivate *priv;

	g_return_if_fail (MY_IS_STUDENT (student));

	priv = student->priv;

	g_free (priv->goals);
	priv->goals = g_strdup (goals);
	g_object_notify_by_pspec (G_OBJECT (student),
	                          gParamSpecs[PROP_GOALS]);
}

/**
 * my_student_get_last_name:
 * @student: (in): A #MyStudent.
 *
 * Fetches the "last-name" property which contains the last name of the
 * student.
 *
 * Returns: (transfer none): A string containing the students last name.
 */
const gchar *
my_student_get_last_name (MyStudent *student)
{
	g_return_val_if_fail (MY_IS_STUDENT (student), NULL);
	return student->priv->last_name;
}

/**
 * my_student_set_last_name:
 * @student: (in): A #MyStudent.
 * @last_name: (in): (allow-none): A string.
 *
 * Sets the "last-name" property which is the last name of the student.
 */
void
my_student_set_last_name (MyStudent   *student,
                          const gchar *last_name)
{
	MyStudentPrivate *priv;

	g_return_if_fail (MY_IS_STUDENT (student));

	priv = student->priv;

	g_free (priv->last_name);
	priv->last_name = g_strdup (last_name);
	g_object_notify_by_pspec (G_OBJECT (student),
	                          gParamSpecs[PROP_LAST_NAME]);
}

/**
 * my_student_get_timezone:
 * @student: (in): A #MyStudent.
 *
 * Fetches the "timezone" property which is the timezone of the student.
 *
 * Returns: (transfer none): A #GTimeZone representing the students timezone.
 */
GTimeZone *
my_student_get_timezone (MyStudent *student)
{
	g_return_val_if_fail (MY_IS_STUDENT (student), NULL);
	return student->priv->timezone;
}

/**
 * my_student_set_timezone:
 * @student: (in): A #MyStudent.
 * @timezone: (in) (allow-none): A #GTimeZone.
 *
 * Sets the "timezone" property which is the timezone of the student.
 */
void
my_student_set_timezone (MyStudent *student,
                         GTimeZone *timezone)
{
	MyStudentPrivate *priv;

	g_return_if_fail (MY_IS_STUDENT (student));

	priv = student->priv;

	if (priv->timezone) {
		g_time_zone_unref (priv->timezone);
		priv->timezone = NULL;
	}

	if (timezone) {
		priv->timezone = g_time_zone_ref (timezone);
	}

	g_object_notify_by_pspec (G_OBJECT (student),
	                          gParamSpecs[PROP_TIMEZONE]);
}

static void
my_student_finalize (GObject *object)
{
	MyStudentPrivate *priv;

	priv = MY_STUDENT (object)->priv;

	g_free (priv->experience);
	g_free (priv->first_name);
	g_free (priv->goals);
	g_free (priv->last_name);
	if (priv->timezone) {
		g_time_zone_unref (priv->timezone);
	}

	G_OBJECT_CLASS (my_student_parent_class)->finalize (object);
}

static void
my_student_get_property (GObject    *object,
                         guint       prop_id,
                         GValue     *value,
                         GParamSpec *pspec)
{
	MyStudent *student = MY_STUDENT (object);

	switch (prop_id) {
	case PROP_CHAPTER:
		g_value_set_uint (value, my_student_get_chapter (student));
		break;
	case PROP_EXPERIENCE:
		g_value_set_string (value, my_student_get_experience (student));
		break;
	case PROP_FIRST_NAME:
		g_value_set_string (value, my_student_get_first_name (student));
		break;
	case PROP_GOALS:
		g_value_set_string (value, my_student_get_goals (student));
		break;
	case PROP_LAST_NAME:
		g_value_set_string (value, my_student_get_last_name (student));
		break;
	case PROP_TIMEZONE:
		g_value_set_boxed (value, my_student_get_timezone (student));
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
	MyStudent *student = MY_STUDENT (object);

	switch (prop_id) {
	case PROP_CHAPTER:
		my_student_set_chapter (student, g_value_get_uint (value));
		break;
	case PROP_EXPERIENCE:
		my_student_set_experience (student, g_value_get_string (value));
		break;
	case PROP_FIRST_NAME:
		my_student_set_first_name (student, g_value_get_string (value));
		break;
	case PROP_GOALS:
		my_student_set_goals (student, g_value_get_string (value));
		break;
	case PROP_LAST_NAME:
		my_student_set_last_name (student, g_value_get_string (value));
		break;
	case PROP_TIMEZONE:
		my_student_set_timezone (student, g_value_get_boxed (value));
		break;
	default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
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
	g_type_class_add_private (object_class, sizeof (MyStudentPrivate));

	gParamSpecs[PROP_CHAPTER] =
		g_param_spec_uint ("chapter",
		                   _("Chapter"),
		                   _("The students current chapter."),
		                   0,
		                   G_MAXUINT,
		                   0,
		                   G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS);
	g_object_class_install_property (object_class, PROP_CHAPTER,
	                                 gParamSpecs[PROP_CHAPTER]);

	gParamSpecs[PROP_EXPERIENCE] =
		g_param_spec_string ("experience",
		                     _("Experience"),
		                     _("The students current experience."),
		                     NULL,
		                     G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS);
	g_object_class_install_property (object_class, PROP_EXPERIENCE,
	                                 gParamSpecs[PROP_EXPERIENCE]);

	gParamSpecs[PROP_FIRST_NAME] =
		g_param_spec_string ("first-name",
		                     _("First name"),
		                     _("The first name of the student."),
		                     NULL,
		                     G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS);
	g_object_class_install_property (object_class, PROP_FIRST_NAME,
	                                 gParamSpecs[PROP_FIRST_NAME]);

	gParamSpecs[PROP_GOALS] =
		g_param_spec_string ("goals",
		                     _("Goals"),
		                     _("The goals of the student."),
		                     NULL,
		                     G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS);
	g_object_class_install_property (object_class, PROP_GOALS,
	                                 gParamSpecs[PROP_GOALS]);

	gParamSpecs[PROP_LAST_NAME] =
		g_param_spec_string ("last-name",
		                     _("Last name"),
		                     _("The last name of the student."),
		                     NULL,
		                     G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS);
	g_object_class_install_property (object_class, PROP_LAST_NAME,
	                                 gParamSpecs[PROP_LAST_NAME]);

	gParamSpecs[PROP_TIMEZONE] =
		g_param_spec_boxed ("timezone",
		                     _("Timezone"),
		                     _("The timezone of the student."),
		                     G_TYPE_TIME_ZONE,
		                     G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS);
	g_object_class_install_property (object_class, PROP_TIMEZONE,
	                                 gParamSpecs[PROP_TIMEZONE]);
}

static void
my_student_init (MyStudent *student)
{
	student->priv = G_TYPE_INSTANCE_GET_PRIVATE(student,
	                                            MY_TYPE_STUDENT,
	                                            MyStudentPrivate);
}
