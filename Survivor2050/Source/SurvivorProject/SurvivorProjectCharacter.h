// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/Character.h"
#include "SurvivorProjectCharacter.generated.h"

class UInputComponent;

UCLASS(config=Game)
class ASurvivorProjectCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Pawn mesh: 1st person view (arms; seen only by self) */
	UPROPERTY(VisibleDefaultsOnly, Category=Mesh)
	class USkeletalMeshComponent* Mesh1P;

	/** Gun mesh: 1st person view (seen only by self) */
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
	class USkeletalMeshComponent* FP_Gun;

	/** First person camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FirstPersonCameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USphereComponent* CollectionSphere;
public:
	ASurvivorProjectCharacter();

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;

	/** Gun muzzle's offset from the characters location */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Gameplay)
	FVector GunOffset;

	/** Projectile class to spawn */
	UPROPERTY(EditDefaultsOnly, Category=Projectile)
	TSubclassOf<class ASurvivorProjectProjectile> ProjectileClass;

	/** Projectile class to spawn */
	UPROPERTY(EditDefaultsOnly, Category = Projectile)
	TSubclassOf<class ASurvivorProjectProjectile> RightMouseProjectileClass;

	/** Sound to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Gameplay)
	class USoundBase* FireSound;

	/** AnimMontage to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	class UAnimMontage* FireAnimation;

	/** Accessor function for gun's initial power */
	UFUNCTION(BlueprintPure, Category = "Power")
		float GetInitialGunPower();

	/** Accessor function for  gun's current power */
	UFUNCTION(BlueprintPure, Category = "Power")
		float GetCurrentGunPower();

   /** Function to update the gun's power
		 @param PowerChange This is the amount to change the power by, and it can be positive or negative. */
	UFUNCTION(BlueprintCallable, Category = "Power")
	void UpdateGunPower(float PowerChange);

	/** Accessor function for initial character power */
	UFUNCTION(BlueprintPure, Category = "Power")
		float GetInitialCharacterPower();

	/** Accessor function for current character power */
	UFUNCTION(BlueprintPure, Category = "Power")
		float GetCurrentCharacterPower();

	/** Function to update the character's power
	@param PowerChange This is the amount to change the power by, and it can be positive or negative. */
	UFUNCTION(BlueprintCallable, Category = "Power")
		void UpdateCharacterPower(float PowerChange);

protected:
	
	/** Fires a projectile. */
	void OnFire();
	void OnRightMouseFire();

	/** Handles moving forward/backward */
	void MoveForward(float Val);

	/** Handles stafing movement, left and right */
	void MoveRight(float Val);

	/**
	 * Called via input to turn at a given rate.
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate.
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

	struct TouchData
	{
		TouchData() { bIsPressed = false;Location=FVector::ZeroVector;}
		bool bIsPressed;
		ETouchIndex::Type FingerIndex;
		FVector Location;
		bool bMoved;
	};
	void BeginTouch(const ETouchIndex::Type FingerIndex, const FVector Location);
	void EndTouch(const ETouchIndex::Type FingerIndex, const FVector Location);
	void TouchUpdate(const ETouchIndex::Type FingerIndex, const FVector Location);
	TouchData	TouchItem;
	
protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(UInputComponent* InputComponent) override;
	// End of APawn interface

	/* 
	 * Configures input for touchscreen devices if there is a valid touch interface for doing so 
	 *
	 * @param	InputComponent	The input component pointer to bind controls to
	 * @returns true if touch controls were enabled.
	 */
	bool EnableTouchscreenMovement(UInputComponent* InputComponent);

	/** Starting power level of character*/
	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "Power", Meta = (BlueprintProtected = "true"))
		float InitialCharacterPower;

	/** Starting power level of gun*/
	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "Power", Meta = (BlueprintProtected = "true"))
		float InitialGunPower;

public:
	/** Returns Mesh1P subobject **/
	FORCEINLINE class USkeletalMeshComponent* GetMesh1P() const { return Mesh1P; }
	/** Returns FirstPersonCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetFirstPersonCameraComponent() const { return FirstPersonCameraComponent; }

	FORCEINLINE class USphereComponent* GetCollectionSphere() const { return CollectionSphere; }

	UFUNCTION(BlueprintCallable, Category = "Pickups")
	void CollectPickups();

private:
	UPROPERTY(VisibleAnywhere, Category = "Power")
		float GunPower;

	UPROPERTY(VisibleAnywhere, Category = "Power")
		float CharacterPower;


};

