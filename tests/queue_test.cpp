#include <gtest/gtest.h>

extern "C" {
    #include "../src/queue.h"
    #include <stdio.h>
}

// Test fixture for Queue tests
class QueueTest : public ::testing::Test {
protected:
    Queue* queue;

    void SetUp() override {
        queue = createQueue();
    }

    void TearDown() override {
        while (!isEmpty(queue)) {
            dequeue(queue);
        }
        free(queue);
    }
};

// Test if the queue is initially empty
TEST_F(QueueTest, IsEmptyInitially) {
    EXPECT_TRUE(isEmpty(queue));
}

// Test enqueue operation
TEST_F(QueueTest, Enqueue) {
    enqueue(queue, 10);
    EXPECT_FALSE(isEmpty(queue));
    EXPECT_EQ(queue->front->data, 10);
    EXPECT_EQ(queue->rear->data, 10);
}

// Test dequeue operation
TEST_F(QueueTest, Dequeue) {
    enqueue(queue, 10);
    enqueue(queue, 20);
    dequeue(queue);
    EXPECT_FALSE(isEmpty(queue));
    EXPECT_EQ(queue->front->data, 20);
    dequeue(queue);
    EXPECT_TRUE(isEmpty(queue));
}

// Test multiple enqueue and dequeue operations
TEST_F(QueueTest, MultipleEnqueueDequeue) {
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    dequeue(queue);
    EXPECT_EQ(queue->front->data, 20);
    dequeue(queue);
    EXPECT_EQ(queue->front->data, 30);
    dequeue(queue);
    EXPECT_TRUE(isEmpty(queue));
}

// Test dequeuing an empty queue
TEST_F(QueueTest, EmptyQueueDequeue) {
    EXPECT_TRUE(isEmpty(queue));
    dequeue(queue);
    EXPECT_TRUE(isEmpty(queue));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}