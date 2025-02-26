#include "detector.hh"

MySensitiveDetector::MySensitiveDetector(G4String name) : G4VSensitiveDetector(name)
{}

MySensitiveDetector::~MySensitiveDetector()
{}


G4bool MySensitiveDetector::ProcessHits(G4Step *aStep, G4TouchableHistory *ROhist)
{

	G4Track *track = aStep->GetTrack();

	track->SetTrackStatus(fStopAndKill);

	G4StepPoint *preStepPoint = aStep->GetPreStepPoint();
	G4StepPoint *postStepPoint = aStep->GetPostStepPoint();

	G4ThreeVector posPhoton = preStepPoint->GetPosition();

//	G4cout << "Photon position" << posPhoton << G4endl; (// it !!!)

	const G4VTouchable *touchable = aStep->GetPreStepPoint()->GetTouchable();
	G4int copyNo = touchable->GetCopyNumber();

// 	G4cout << "Copy number:" << copyNo << G4endl; (// it unless we want to know the copy number)

	G4VPhysicalVolume *physVol = touchable->GetVolume();
	G4ThreeVector posDetector = physVol->GetTranslation();
	G4cout << "detector position:" << posDetector << G4endl;

}
