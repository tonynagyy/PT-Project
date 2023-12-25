#pragma once
#include "Action.h"
#include "..\ApplicationManager.h"
#define MAX_SIZE 20

class StartRecAction : public Action {
	private:
		bool canStartRec;
		Action *queue[MAX_SIZE] ;
		int front;
		int rear;
	public:
		StartRecAction(ApplicationManager *pApp);
		~StartRecAction();
		void ReadActionParameters() override;
		void Execute() override;
		void undo() override;
		StartRecAction* clone() const override;
		bool canStartRecd();
		bool ckeckActionValidity(const ActionType &) const;
		/*queue functions*/
		bool isEmpty() const;
		bool isFull() const;
		void enqueue(Action *);
		Action* dequeue();
		void displayQueue() const;//for testing
		Action *getFront() const;	
		Action *getRear() const;
		int getQueueSize() const;
};
