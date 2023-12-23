#pragma once
#include "Action.h"
#include "..\ApplicationManager.h"
#define MAX_SIZE 20

class StartRecAction : public Action {
	private:
		bool isValid;
		Action *queue[MAX_SIZE] ;
		int front;
		int rear;
		int size;
	public:
		StartRecAction(ApplicationManager *pApp);
		void ReadActionParameters() override;
		void Execute() override;
		void undo() override;
		StartRecAction* clone() const override;
		bool ckeckValidty();
		bool ckeckActionValidity(const ActionType &) const;
		/*queue functions*/
		bool isEmpty() const;
		bool isFull() const;
		void enqueue(Action *);
		Action* dequeue();
		Action* peek() const;
		void clear();

		
		

	
};
