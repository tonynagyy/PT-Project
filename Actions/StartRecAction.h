#pragma once
#include "Action.h"
#include "..\ApplicationManager.h"
#define MAX_SIZE 20

class StartRecAction : public Action {
	private:
		Action *queue[MAX_SIZE] ;
		int front;
		int rear;
		bool canStartRec;
	public:
		StartRecAction(ApplicationManager *pApp);
		StartRecAction(const StartRecAction &other);
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
		void displayQueue() const;//for testing
		int getQueueSize() const;
		void setFrontIndex(int idx);
		void setRearIndex(int idx);
		Action *getFront() const;	
		Action *getRear() const;
		Action* dequeue();
};
