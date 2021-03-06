#ifndef TODOS_MODEL_TRAITS_CATEGORYTRAITS_H
#define TODOS_MODEL_TRAITS_CATEGORYTRAITS_H

#include <model/traits/IEntityTraits.h>

namespace todos_model_traits {
  class CategoryTraits: public IEntityTraits
  {
  public:
    virtual FieldsNamesContainer GetFieldsNames() const override;
    virtual const char* GetTableName() const override;
    virtual const char *GetIdFieldName() const override;
  };
}

#endif //TODOS_MODEL_TRAITS_CATEGORYTRAITS_H
