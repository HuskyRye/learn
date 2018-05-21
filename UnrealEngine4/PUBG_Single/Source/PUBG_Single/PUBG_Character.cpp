/*
    Author: 刘臣轩
    Date: 2018.5.17
*/

#include "PUBG_Character.h"

#include "Components/ArrowComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
APUBG_Character::APUBG_Character()
{
    // Set this character to call Tick() every frame.
    PrimaryActorTick.bCanEverTick = false;

    bUseControllerRotationPitch = false;
    bUseControllerRotationYaw = true;
    bUseControllerRotationRoll = false;

    static ConstructorHelpers::FObjectFinder<USkeletalMesh> CharacterMesh(TEXT("/Game/Girl_01/meshes/girl_01_a"));
    GetMesh()->SetSkeletalMesh(CharacterMesh.Object);
    GetMesh()->SetRelativeLocation(FVector(0, 0, -90));
    GetMesh()->SetRelativeRotation(FRotator(0, -90, 0));

    SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
    SpringArm->SetupAttachment(RootComponent);
    SpringArm->TargetArmLength = 200;
    SpringArm->SetRelativeLocation(FVector(0, 0, 100));
    SpringArm->SocketOffset = FVector(0, 25, 0);
    SpringArm->bUsePawnControlRotation = true;

    FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
    FollowCamera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
}

// Called when the game starts or when spawned
void APUBG_Character::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void APUBG_Character::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void APUBG_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
    PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
    PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

    PlayerInputComponent->BindAxis("MoveForward", this, &APUBG_Character::MoveForward);
    PlayerInputComponent->BindAxis("MoveRight", this, &APUBG_Character::MoveRight);

    PlayerInputComponent->BindAxis("Turn", this, &ACharacter::AddControllerYawInput);
    PlayerInputComponent->BindAxis("LookUp", this, &ACharacter::AddControllerPitchInput);
}

void APUBG_Character::MoveForward(float AxisValue)
{
    if (AxisValue)
        AddMovementInput(GetActorForwardVector(), AxisValue);
}

void APUBG_Character::MoveRight(float AxisValue)
{
    if (AxisValue)
        AddMovementInput(GetActorRightVector(), AxisValue);
}