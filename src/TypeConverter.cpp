#include "TypeConverter.h"

namespace
{
	const QString csLowPriority     = QString("Low");
	const QString csNormalPriority  = QString("Normal");
	const QString csHighPriority    = QString("High");
	const QString csUnknownPriority = QString("Unknown");

	const QString csCompletedStatus   = QString("Completed");
	const QString csUncompletedStatus = QString("Uncompleted");
	const QString csUnknownStatus     = QString("Unknown");

	const QString csTextType     = QString("TextType");
	const QString csImagePNGType = QString("ImagePNGType");
	const QString csUnknownType  = QString("UnknownType");

	const QString csNoneSort = QString("None");
	const QString csDueDateSort = QString("Due date");
	const QString csPrioritySort = QString("Priority");
	const QString csTitleSort = QString("Title");
}

QString TypeConverter::toString(Priority priority)
{
	switch (priority) {
	case Priority::LOW:
		return csLowPriority;
	case Priority::NORMAL:
		return csNormalPriority;
	case Priority::HIGH:
		return csHighPriority;
	default:
		return csUnknownPriority;
	}
}

Priority TypeConverter::toPriority(const QString &str)
{
	if (str == csLowPriority) {
		return Priority::LOW;
	} else if (str == csNormalPriority) {
		return Priority::NORMAL;
	} else if (str == csHighPriority) {
		return Priority::HIGH;
	} else {
		return Priority::UNKNOWN;
	}
}

QString TypeConverter::toString(Status status)
{
	switch (status) {
	case Status::COMPLETED:
		return csCompletedStatus;
	case Status::UNCOMPLETED:
		return csUncompletedStatus;
	default:
		return csUnknownStatus;
	}
}

Status TypeConverter::toStatus(const QString &str)
{
	if (str == csCompletedStatus) {
		return Status::COMPLETED;
	} else if (str == csUncompletedStatus) {
		return Status::UNCOMPLETED;
	} else {
		return Status::UNKNOWN;
	}
}

QString TypeConverter::toString(CommentaryType type)
{
	switch (type) {
	case CommentaryType::TEXT:
		return csTextType;
	case CommentaryType::IMAGE_PNG:
		return csImagePNGType;
	default:
		return csUnknownType;
	}
}

CommentaryType TypeConverter::toCommentaryType(const QString &str)
{
	if (str == csTextType) {
		return CommentaryType::TEXT;
	} else if (str == csImagePNGType) {
		return CommentaryType::IMAGE_PNG;
	} else {
		return CommentaryType::UNKNOWN;
	}
}

QString TypeConverter::toString(TaskSortSettings::Field field)
{
	switch (field) {
	case TaskSortSettings::Field::DUE_DATE:
		return csDueDateSort;
	case TaskSortSettings::Field::PRIORITY:
		return csPrioritySort;
	case TaskSortSettings::Field::TITLE:
		return csTitleSort;
	default:
		return csNoneSort;
	}
}

TaskSortSettings::Field TypeConverter::toTaskSortField(const QString &str)
{
	if (str == csDueDateSort) {
		return TaskSortSettings::Field::DUE_DATE;
	} else if (str == csPrioritySort) {
		return TaskSortSettings::Field::PRIORITY;
	} else if (str == csTitleSort) {
		return TaskSortSettings::Field::TITLE;
	} else {
		return TaskSortSettings::Field::NONE;
	}
}
