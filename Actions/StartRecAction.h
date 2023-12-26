#pragma once
#include "Action.h"
#include "..\ApplicationManager.h"
#include "..\StopRecAction.h"
#define MAX_SIZE 20

/*
* Class: StartRecAction inherited from Action
* @param queue of actions
* @param front index of the queue
* @param rear index of the queue
* @param canStartRec boolean to check if the recording can start
* Description: This class is responsible for starting the recording of the actions
* and adding them to the queue
*/
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

		/*Actions Operatrions*/
		void ReadActionParameters() override;
		void Execute() override;
		void undo() override;
		StartRecAction* clone() const override;

		/*Validity chkeck and getters*/
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
