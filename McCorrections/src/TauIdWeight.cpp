/*! Various lepton weights.
This file is part of https://github.com/hh-italian-group/h-tautau. */

#include "h-tautau/McCorrections/include/TauIdWeight.h"

namespace analysis {
namespace mc_corrections {

double TauIdWeight2016::GetIdIsoSF(const LorentzVectorM_Float& /*p4*/, GenMatch /*gen_match*/, int /*decay_mode*/,
                                   DiscriminatorWP /*anti_ele_wp*/, DiscriminatorWP /*anti_mu_wp*/,
                                   DiscriminatorWP /*iso_wp*/) const
{
    return 1;
}

double TauIdWeight2016::GetTauIdEfficiencyUncertainty(DiscriminatorWP /*iso_wp*/, GenMatch /*gen_match*/) const
{
    return 0;
}

double TauIdWeight2016::GetMuonMissIdUncertainty(const LorentzVectorM_Float& /*p4*/, GenMatch /*gen_match*/,
                                                 DiscriminatorWP /*anti_mu_wp*/) const
{
    return 0;
}

double TauIdWeight2016::GetEleMissIdUncertainty(const LorentzVectorM_Float& /*p4*/, GenMatch /*gen_match*/,
                                                DiscriminatorWP /*anti_ele_wp*/) const
{
    return 0;
}


double TauIdWeight2017::GetIdIsoSF(const LorentzVectorM_Float& p4, GenMatch gen_match, int /*decay_mode*/,
                                   DiscriminatorWP anti_ele_wp, DiscriminatorWP anti_mu_wp,
                                   DiscriminatorWP iso_wp) const
{
    auto tauSF = getTauIso(iso_wp, gen_match).GetValue();
    auto muonSF = getMuonMissId(p4, gen_match, anti_mu_wp).GetValue();
    auto eleSF = getEleMissId(p4, gen_match, anti_ele_wp).GetValue();

    return tauSF * muonSF * eleSF;
}

double TauIdWeight2017::GetTauIdEfficiencyUncertainty(DiscriminatorWP iso_wp, GenMatch gen_match) const
{
    return getTauIso(iso_wp, gen_match).GetRelativeStatisticalError();
}

double TauIdWeight2017::GetMuonMissIdUncertainty(const LorentzVectorM_Float& p4, GenMatch gen_match,
                                                 DiscriminatorWP anti_mu_wp) const
{
    return getMuonMissId(p4, gen_match, anti_mu_wp).GetRelativeStatisticalError();
}

double TauIdWeight2017::GetEleMissIdUncertainty(const LorentzVectorM_Float& p4, GenMatch gen_match,
                                                DiscriminatorWP anti_ele_wp) const
{
    return getEleMissId(p4, gen_match, anti_ele_wp).GetRelativeStatisticalError();
}

PhysicalValue TauIdWeight2017::getMuonMissId(const LorentzVectorM_Float& p4, GenMatch gen_match,
                                             DiscriminatorWP iso_wp) const
{
    //https://indico.cern.ch/event/738043/contributions/3048471/attachments/1674773/2691664/TauId_26062018.pdf
    //https://twiki.cern.ch/twiki/bin/viewauth/CMS/TauIDRecommendation13TeV

    if (!(gen_match == GenMatch::Muon || gen_match == GenMatch::TauMuon))
        return PhysicalValue(1,0);

    if(!(iso_wp == DiscriminatorWP::Loose || iso_wp == DiscriminatorWP::Tight))
        throw exception("WP %1% is not supported.") % iso_wp;

    if(std::abs(p4.eta()) < 0.4)
        return iso_wp == DiscriminatorWP::Loose ? PhysicalValue(1.06,0.05) : PhysicalValue(1.17,0.12);

    else if(std::abs(p4.eta()) >= 0.4 && std::abs(p4.eta()) < 0.8)
        return iso_wp == DiscriminatorWP::Loose ? PhysicalValue(1.02,0.04) : PhysicalValue(1.29,0.30);

    else if(std::abs(p4.eta()) >= 0.8 && std::abs(p4.eta()) < 1.2)
        return iso_wp == DiscriminatorWP::Loose ? PhysicalValue(1.10,0.04) : PhysicalValue(1.14,0.05);

    else if(std::abs(p4.eta()) >= 1.2 && std::abs(p4.eta()) < 1.7)
        return iso_wp == DiscriminatorWP::Loose ? PhysicalValue(1.03,0.18) : PhysicalValue(0.93,0.60);

    else if(std::abs(p4.eta()) >=1.7 && std::abs(p4.eta()) < 2.3)
                return iso_wp == DiscriminatorWP::Loose ? PhysicalValue(1.94,0.35) : PhysicalValue(1.61,0.60);

    else throw exception("eta out of range");
}

PhysicalValue TauIdWeight2017::getEleMissId(const LorentzVectorM_Float& p4, GenMatch gen_match,
                                            DiscriminatorWP iso_wp) const
{
    //https://indico.cern.ch/event/738043/contributions/3048471/attachments/1674773/2691664/TauId_26062018.pdf
    //https://twiki.cern.ch/twiki/bin/viewauth/CMS/TauIDRecommendation13TeV

    if (!(gen_match == GenMatch::Electron || gen_match == GenMatch::TauElectron))
        return PhysicalValue(1,0);

    //Barrel ( abs(eta) < 1.460)
    if(std::abs(p4.eta()) < 1.460){
        if(iso_wp == DiscriminatorWP::VLoose)
            return PhysicalValue(1.09,0.01);
        else if(iso_wp == DiscriminatorWP::Loose)
            return PhysicalValue(1.17,0.04);
        else if(iso_wp == DiscriminatorWP::Medium)
            return  PhysicalValue(1.40,0.12);
        else if(iso_wp == DiscriminatorWP::Tight)
            return  PhysicalValue(1.80,0.20);
        else if(iso_wp == DiscriminatorWP::VTight)
            return PhysicalValue(1.96,0.27);

        else throw exception("WP %1% is not supported.") % iso_wp;
    }

    // Endcaps ( abs(eta) > 1.558)
    else if(std::abs(p4.eta()) > 1.558){
        if(iso_wp == DiscriminatorWP::VLoose)
            return PhysicalValue(1.19,0.01);
        else if(iso_wp == DiscriminatorWP::Loose)
            return PhysicalValue(1.25,0.06);
        else if(iso_wp == DiscriminatorWP::Medium)
            return PhysicalValue(1.21,0.26);
        else if(iso_wp == DiscriminatorWP::Tight)
            return PhysicalValue(1.53,0.60);
        else if(iso_wp == DiscriminatorWP::VTight)
            return PhysicalValue(1.66,0.80);

        else throw exception("WP %1% is not supported.") % iso_wp;
    }

    //Gap between barrel and endcaps
    else if(std::abs(p4.eta()) >= 1.460 && std::abs(p4.eta()) <= 1.558)
        return PhysicalValue(1,0);

    else throw exception("eta out of range");
}

//Isolation sum with deltaR=0.5
PhysicalValue TauIdWeight2017::getTauIso(DiscriminatorWP iso_wp, GenMatch gen_match) const
{
    //https://twiki.cern.ch/twiki/bin/viewauth/CMS/TauIDRecommendation13TeV
    //https://indico.cern.ch/event/738043/contributions/3048471/attachments/1674773/2691664/TauId_26062018.pdf

    if(gen_match == GenMatch::Tau){
        if(iso_wp == DiscriminatorWP::VLoose)
            return  PhysicalValue(0.88,0.03);
        else if(iso_wp == DiscriminatorWP::Loose || iso_wp == DiscriminatorWP::Medium || iso_wp == DiscriminatorWP::Tight)
            return  PhysicalValue(0.89,0.03);
        else if(iso_wp == DiscriminatorWP::VTight)
            return  PhysicalValue(0.86,0.03);
        else if(iso_wp == DiscriminatorWP::VVTight)
            return  PhysicalValue(0.84,0.03);
        else throw exception("WP %1% is not supported.") % iso_wp;
    }
    else
        return PhysicalValue(1,0);
}

PhysicalValue TauIdWeight2017::getDmDependentTauIso(GenMatch gen_match, int decay_mode) const
{

    std::map<int, double> decay_SF_map = {{0, 1.06}, {1,1.01}, {10, 0.90}};

    if (gen_match == GenMatch::Tau)
        return PhysicalValue(decay_SF_map[decay_mode],0);
    else
        return PhysicalValue(1,0);
}

} // namespace mc_corrections
} // namespace analysis