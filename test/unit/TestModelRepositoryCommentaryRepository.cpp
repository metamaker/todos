#include <gtest/gtest.h>

#include <model/repository/Commentary/CommentaryRepository.h>

using todos_model_entity::Commentary;
using todos_model_repository::CommentaryRepository;
using todos_model_schema::Schema;

class TestModelRepositoryCommentaryRepository : public ::testing::Test
{
protected:
  Schema m_db;

public:
  TestModelRepositoryCommentaryRepository() : m_db(nullptr)
  {
  }

protected:
  virtual void SetUp()
  {
    remove("test-db-Commentary.sqlite3");
    m_db.Open("test-db-Commentary.sqlite3");
    m_db.CreateTables();
  }

  virtual void TearDown()
  {
    m_db.Close();
    remove("test-db-Commentary.sqlite3");
  }
};

TEST_F(TestModelRepositoryCommentaryRepository, CommentaryRepositoryInsertOneEntity)
{
  CommentaryRepository repository(m_db);

  Commentary entity(0, 1, Commentary::Type::TEXT, QDateTime(QDate(2015, 12, 14), QTime(12, 12)), "Test text");
  unsigned long insertId = repository.Insert(entity);

  ASSERT_TRUE(insertId != 0);

  auto foundEntity = repository.FindOneById(insertId);

  ASSERT_TRUE(foundEntity != nullptr);
  EXPECT_TRUE(foundEntity->GetContent() == entity.GetContent());
}

TEST_F(TestModelRepositoryCommentaryRepository, CommentaryRepositoryUpdateOneEntity)
{
  CommentaryRepository repository(m_db);
  Commentary entity(0, 1, Commentary::Type::TEXT, QDateTime(QDate(2015, 12, 14), QTime(12, 12)), "1");
  Commentary updatedEntity(0, 1, Commentary::Type::TEXT, QDateTime(QDate(2005, 12, 14), QTime(12, 12)), "2");

  unsigned long insertId = repository.Insert(entity);
  ASSERT_TRUE(insertId != 0);

  CommentaryRepository::EntitySharedPtr foundEntity = repository.FindOneById(insertId);
  ASSERT_TRUE(foundEntity != nullptr);
  EXPECT_TRUE(foundEntity->GetContent() == entity.GetContent());

  repository.Update(insertId, updatedEntity);

  foundEntity = repository.FindOneById(updatedEntity.GetId());
  ASSERT_TRUE(foundEntity != nullptr);
  ASSERT_TRUE(foundEntity->GetContent() == updatedEntity.GetContent());
}

TEST_F(TestModelRepositoryCommentaryRepository, CommentaryRepositoryDeleteOneEntity)
{
  CommentaryRepository repository(m_db);
  Commentary entity(0, 1, Commentary::Type::TEXT, QDateTime(QDate(2015, 12, 14), QTime(12, 12)), "Test text");

  unsigned long insertId = repository.Insert(entity);
  ASSERT_TRUE(insertId != 0);

  CommentaryRepository::EntitySharedPtr foundEntity = repository.FindOneById(insertId);
  ASSERT_TRUE(foundEntity != nullptr);

  unsigned long deletedCount = repository.Delete(insertId);
  ASSERT_TRUE(deletedCount == 1);

  foundEntity = repository.FindOneById(insertId);
  EXPECT_TRUE(foundEntity == nullptr);
}

TEST_F(TestModelRepositoryCommentaryRepository, CommentaryRepositoryFindAll)
{
  CommentaryRepository repository(m_db);
  Commentary entity1(0, 1, Commentary::Type::TEXT, QDateTime(QDate(2015, 12, 14), QTime(12, 12)), "Test text 1");
  Commentary entity2(0, 1, Commentary::Type::TEXT, QDateTime(QDate(2015, 12, 14), QTime(23, 12)), "Test text 3");
  Commentary entity3(0, 1, Commentary::Type::TEXT, QDateTime(QDate(2015, 12, 14), QTime(14, 12)), "Test text 2");
  Commentary entity4(0, 2, Commentary::Type::TEXT, QDateTime(QDate(2015, 12, 14), QTime(14, 12)), "Test text ?");

  repository.Insert(entity1);
  repository.Insert(entity2);
  repository.Insert(entity3);
  repository.Insert(entity4);

  std::vector<std::shared_ptr<Commentary> > foundEntities = repository.FindAll(1);

  EXPECT_TRUE(foundEntities.size() == 3);
}
