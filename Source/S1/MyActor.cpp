// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include "Protocol.pb.h"
#include "S1GameInstance.h"
#include "ClientPacketHandler.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Protocol::C_CHAT Msg;
	Msg.set_msg("Hello Rookiss");
	SendBufferRef SendBuffer = ClientPacketHandler::MakeSendBuffer(Msg);
	Cast<US1GameInstance>(GetGameInstance())->SendPacket(SendBuffer);
}

