#ifndef TODOS_MODEL_ENTITY_COMMENTARY_H
#define TODOS_MODEL_ENTITY_COMMENTARY_H

#include <string>
#include <memory>
#include <QDateTime>

#include <model/entity/IEntity.h>

namespace todos_model_entity {
  class Commentary: public IEntity
  {
  public:
    enum class Type {
      UNKNOWN = 0,

      TEXT = 1,
      IMAGE_PNG = 2
    };

    typedef QDateTime DateTime;
    typedef std::string Content;

  private:
    Type m_type;
    DateTime m_publishedOn;
    Content m_content;

  public:
    Commentary(unsigned long id, Type type, const DateTime& publishedOn, const Content& content);

    Type GetType() const;
    DateTime GetPublishedOn() const;
    Content GetContent() const;

    void SetType(Type type);
    void SetPublishedOn(const DateTime& publishedOn);
    void SetContent(const Content& content);
  };
}

#endif //TODOS_MODEL_ENTITY_COMMENTARY_H
