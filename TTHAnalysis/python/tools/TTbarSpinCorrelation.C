#include "TFile.h"
#include "Math/Boost.h"
#include "TLorentzVector.h"
#include "TVector3.h"
#include "TH2D.h"
//typedef ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > LorentzVector;
float ttbarPolarizationAngle(TLorentzVector p4top, TLorentzVector p4lepton){
  
  TVector3 boost_t = p4top.BoostVector();;
  p4lepton.Boost(-boost_t);
  float lepton_cos_theta =  cos(p4lepton.Vect().Angle(p4top.Vect()));
 
  return lepton_cos_theta;

}

float ttbarPolarizationreturnWeight(float t, float at){

  TFile* theFile = new TFile("../python/tools/TopSpinCorWeights.root");
  TH2D* hist = (TH2D*) theFile->Get("cos2D");
  int binX = hist->GetXaxis()->FindBin(t);
  int binY = hist->GetYaxis()->FindBin(at);
  float weight = hist->GetBinContent(binX,binY);
  delete theFile;
  return weight;
  
}
