/*! Definition of a tuple with all event information that is required at the analysis level.
This file is part of https://github.com/hh-italian-group/h-tautau. */

#pragma once

#include "AnalysisTools/Core/include/SmartTree.h"
#include "AnalysisTools/Core/include/AnalysisMath.h"
#include "DiscriminatorIdResults.h"
#include "TauIdResults.h"

namespace ntuple {
using LorentzVectorE = analysis::LorentzVectorE_Float;
using LorentzVectorM = analysis::LorentzVectorM_Float;
using MetCovMatrix = analysis::SquareMatrix<2>;
using Point3D = analysis::Point3D_Float;
}

#define LVAR(type, name) VAR(std::vector<type>, lep_##name)
#define OTHERVAR(type, name, col) VAR(std::vector<type>, col##_##name)
#define TAU_ID(name, pattern, has_raw, wp_list) VAR(std::vector<uint16_t>, name) VAR(std::vector<Float_t>, name##raw)

#define LEG_DATA() \
    LVAR(LorentzVectorM, p4) /* 4-momentum */ \
    LVAR(Int_t, q) /* Charge */ \
    LVAR(Int_t, type) /* lepton type: e, mu or tau */ \
    LVAR(Float_t,dxy) /* dxy with respect to primary vertex */ \
    LVAR(Float_t, dz) /* dz with respect to primary vertex */ \
    LVAR(Float_t, iso) /* MVA iso for hadronic Tau, Delta Beta for muon and electron */ \
    LVAR(Int_t, gen_match) /* Generator matching, see Htautau Twiki*/\
    LVAR(LorentzVectorM, gen_p4) /* 4-momentum of the matched gen particle */ \
    LVAR(LorentzVectorM, gen_visible_p4) /* 4-momentum of the matched gen particle */ \
    LVAR(Int_t, gen_chargedParticles) /* tau decay mode */ \
    LVAR(Int_t, gen_neutralParticles) /* tau decay mode */ \
    LVAR(Int_t, decayMode) /* tau decay mode */ \
    LVAR(Bool_t, oldDecayModeFinding) /* tau passed the old decay mode finding requirements */ \
    LVAR(Bool_t, newDecayModeFinding) /* tau passed the new decay mode finding requirements */ \
    LVAR(Bool_t, elePassConversionVeto) /* ele passed conversionVeto requirement */ \
    LVAR(uint16_t, eleId_iso) /* ele passed Id with isolation requirement */ \
    LVAR(uint16_t, eleId_noIso) /* ele passed Id without isolation requirement */ \
    LVAR(uint16_t, muonId) /* muon passed Id requirement */ \
    LVAR(Int_t, genTauIndex) /* tau leg is matched with true tau */ \
    /**/

#define OTHER_LEPTON_DATA(col) \
    OTHERVAR(LorentzVectorM, p4, col) /* 4-momentum */ \
    OTHERVAR(Int_t, q, col) /* Charge */ \
    OTHERVAR(Int_t, type, col) /* Type */ \
    OTHERVAR(Int_t, gen_match, col) /* Generator matching, see Htautau Twiki*/ \
    OTHERVAR(LorentzVectorM, gen_p4, col) /* 4-momentum of the matched gen particle */ \
    OTHERVAR(Float_t, iso, col) /* MVA iso for hadronic Tau, Delta Beta for muon and electron */ \
    OTHERVAR(Bool_t, elePassConversionVeto, col) /* ele passed conversionVeto requirement */ \
    OTHERVAR(uint16_t, eleId_iso, col) /* ele passed Id with isolation requirement */ \
    OTHERVAR(uint16_t, eleId_noIso, col) /* ele passed Id without isolation requirement */ \
    OTHERVAR(uint16_t, muonId, col) /* muon passed Id requirement */ \
    /**/

#define JVAR(type, name, col) VAR(std::vector<type>, col##_##name)

#define JET_DATA(col) \
    JVAR(LorentzVectorE, p4, col) /* Jet 4-momentum */ \
    JVAR(Float_t, csv, col) /* Jet CSV value */ \
    JVAR(Float_t, deepCsv_BvsAll, col) /* Jet deepCSV b+bb value */ \
    JVAR(Float_t, deepCsv_CvsB, col) /* Jet deepCSV c vs b value */ \
    JVAR(Float_t, deepCsv_CvsL, col) /* Jet deepCSV c vs l value */ \
    JVAR(Float_t, deepFlavour_b, col) /* Jet deepFlavour b value */ \
    JVAR(Float_t, deepFlavour_bb, col) /* Jet deepFlavour bb value */ \
    JVAR(Float_t, deepFlavour_lepb, col) /* Jet deepFlavour lepb value */ \
    JVAR(Float_t, deepFlavour_c, col) /* Jet deepFlavour c value */ \
    JVAR(Float_t, deepFlavour_uds, col) /* Jet deepFlavour uds value */ \
    JVAR(Float_t, deepFlavour_g, col) /* Jet deepFlavour g value */ \
    JVAR(Float_t, rawf, col) /* factor to be applied to the jet p4 to obtain its uncorrected p4 */ \
    JVAR(uint16_t, pu_id, col) /* Jet MVA id value */ \
    JVAR(Float_t, pu_id_raw, col) /* Raw jet MVA id value */ \
    JVAR(uint16_t, pu_id_upd, col) /* Updated jet MVA id value */ \
    JVAR(Float_t, pu_id_upd_raw, col) /* Updated raw jet MVA id value */ \
    JVAR(Int_t, partonFlavour, col) \
    JVAR(Int_t, hadronFlavour, col) \
    JVAR(Float_t, resolution, col) /* Jet energy resolution in percentage */ \
    JVAR(ULong64_t, triggerFilterMatch, col) /* Trigger filters matching bits */ \
    JVAR(Int_t, genJetIndex, col) /* b is matched with true b */ \
    JVAR(ULong64_t, triggerFilterMatch_0, col) /* Trigger filters matching bits */ \
    JVAR(ULong64_t, triggerFilterMatch_1, col) /* Trigger filters matching bits */ \
    JVAR(ULong64_t, triggerFilterMatch_2, col) /* Trigger filters matching bits */ \
    JVAR(ULong64_t, triggerFilterMatch_3, col) /* Trigger filters matching bits */ \
    /**/

#define FATJET_DATA(col) \
    JVAR(LorentzVectorE, p4, col) /* Jet 4-momentum */ \
    JVAR(Float_t, m_softDrop, col) \
    JVAR(Float_t, jettiness_tau1, col) \
    JVAR(Float_t, jettiness_tau2, col) \
    JVAR(Float_t, jettiness_tau3, col) \
    JVAR(Float_t, jettiness_tau4, col) \
    /**/

#define SUBJET_DATA(col) \
    JVAR(LorentzVectorE, p4, col) /* Jet 4-momentum */ \
    JVAR(size_t, parentIndex, col) \
    /**/

#define MVAR(type, name, col) VAR(type, col##_##name)

#define MET_DATA(col) \
    MVAR(LorentzVectorM, p4, col) /* MET 4-momentum */ \
    MVAR(MetCovMatrix, cov, col) /* pf met covariance matrix */ \
    /**/

#define EVENT_DATA() \
    VAR(UInt_t, run) /* run */ \
    VAR(UInt_t, lumi) /* lumi section */ \
    VAR(ULong64_t, evt) /* event number */ \
    VAR(Int_t, channelId) /* Channel: eTau, muTau or tauTau */ \
    VAR(Int_t, eventEnergyScale) /* event type category */ \
    VAR(Int_t, genEventType) /* gen event type */ \
    VAR(Float_t, genEventWeight) /* gen event weight */ \
    VAR(Float_t, genEventLHEWeight) /* Nominal event weight in the LHE file */ \
    VAR(std::vector<Float_t>, genEventPSWeights) /* parton shower weights (w_var / w_nominal): \
                                                    [0] is ISR=0.5 FSR=1; [1] is ISR=1 FSR=0.5; \
                                                    [2] is ISR=2 FSR=1; [3] is ISR=1 FSR=2 */ \
    VAR(Bool_t, isData) \
    VAR(Bool_t, isEmbedded) \
    VAR(Int_t, period) /* datataking period */ \
	/* Event Weights Variables */ \
    VAR(Double_t, weight_pu) \
    VAR(Double_t, weight_pu_up) \
    VAR(Double_t, weight_pu_down) \
    VAR(Double_t, weight_dy) \
    VAR(Double_t, weight_ttbar) \
    VAR(Double_t, weight_wjets) \
    VAR(Double_t, weight_bsm_to_sm) \
    VAR(Double_t, weight_top_pt) \
    VAR(Double_t, weight_xs) \
    VAR(Double_t, weight_xs_withTopPt) \
    VAR(Double_t, weight_total) \
    VAR(Double_t, weight_total_withTopPt) \
    /* Event Variables */ \
    VAR(Int_t, npv) /* NPV */ \
    VAR(Float_t, npu) /* Number of in-time pu interactions added to the event */ \
    VAR(Float_t, rho) /* Jet energy density in the event */ \
    /* Trigger results */ \
    VAR(ULong64_t, trigger_accepts) /* Trigger accept bits for the selected triggers */ \
    VAR(std::vector<ULong64_t>, trigger_matches) /* Leg matching results for the selected triggers */ \
    /* SVfit variables */ \
    VAR(std::vector<UInt_t>, SVfit_htt_index) /* SVfit: H->tautau index */ \
    VAR(std::vector<Bool_t>, SVfit_is_valid) /* SVfit: has a valid result */ \
    VAR(std::vector<LorentzVectorM>, SVfit_p4) /* SVfit: 4-momentum */ \
    VAR(std::vector<LorentzVectorM>, SVfit_p4_error) /* SVfit: error on 4-momentum */ \
    VAR(std::vector<Float_t>, SVfit_mt) /* SVfit: transverse mass */ \
    VAR(std::vector<Float_t>, SVfit_mt_error) /* SVfit: error on transverse mass */ \
    VAR(std::vector<Int_t>, SVfit_unc_source) /* SVfit: uncertainty source */ \
    VAR(std::vector<Int_t>, SVfit_unc_scale) /* SVfit: uncertainty scale */ \
    /* Signal leptons */ \
    LEG_DATA() /* muon, electron or tau */ \
    TAU_IDS() /* raw values of tau ID discriminators */ \
    /* Met related variables */ \
    MET_DATA(pfMET) \
    VAR(UInt_t, metFilters) \
    /* Candidate Jets: jets after applying Jet energy corrections (excluding hadronic Tau) */ \
    JET_DATA(jets) \
    VAR(std::vector<LorentzVectorE>, other_jets_p4) /* Other Jet 4-momentum */\
    FATJET_DATA(fatJets) \
    SUBJET_DATA(subJets) \
    /* HHKinFit variables */ \
    VAR(std::vector<UInt_t>, kinFit_htt_index) /* HHKinFit: H->tautau index */ \
    VAR(std::vector<UInt_t>, kinFit_hbb_index) /* HHKinFit: H->bb index */\
    VAR(std::vector<Int_t>, kinFit_unc_source) /* HHKinFit: uncertianty source */ \
    VAR(std::vector<Int_t>, kinFit_unc_scale) /* HHKinFit: uncertainty scale */ \
    VAR(std::vector<Float_t>, kinFit_m) /* HHKinFit: m_bbtt mass */\
    VAR(std::vector<Float_t>, kinFit_chi2) /*  HHKinFit: chi2 value*/ \
    VAR(std::vector<Int_t>, kinFit_convergence) /* HHKinFit: convergence code */\
    /* Jet HH-btag score variables */ \
    VAR(std::vector<UInt_t>, jet_HHbtag_htt_index) /* HH-btag: H->tautau index */ \
    VAR(std::vector<UInt_t>, jet_HHbtag_jet_index) /* HH-btag: jet index */ \
    VAR(std::vector<Int_t>, jet_HHbtag_unc_source) /* HH-btag: uncertainty source */ \
    VAR(std::vector<Int_t>, jet_HHbtag_unc_scale) /* HH-btag: uncertainty scale */ \
    VAR(std::vector<Float_t>, jet_HHbtag_value) /* HH-btag: tagging score */ \
    /* Generator level information */\
    VAR(UInt_t, lhe_n_partons) \
    VAR(UInt_t, lhe_n_c_partons) \
    VAR(UInt_t, lhe_n_b_partons) \
    VAR(Float_t, lhe_HT) \
    VAR(Float_t, lhe_H_m) \
    VAR(Float_t, lhe_hh_m) \
    VAR(Float_t, lhe_hh_cosTheta) \
    VAR(std::vector<Int_t>, lhe_index) \
    VAR(std::vector<Int_t>, lhe_pdgId) \
    VAR(std::vector<Int_t>, lhe_first_mother_index) \
    VAR(std::vector<Int_t>, lhe_last_mother_index) \
    VAR(std::vector<LorentzVectorM>, lhe_p4) \
    VAR(std::vector<Int_t>, genParticles_index) \
    VAR(std::vector<Int_t>, genParticles_status) \
    VAR(std::vector<Point3D>, genParticles_vertex) \
    VAR(std::vector<uint16_t>, genParticles_statusFlags) \
    VAR(std::vector<Int_t>, genParticles_rel_pIndex) \
    VAR(std::vector<Int_t>, genParticles_rel_mIndex) \
    VAR(std::vector<Int_t>, genParticles_pdg) \
    VAR(std::vector<LorentzVectorM>, genParticles_p4) \
    VAR(UInt_t, genParticles_nPromptElectrons) \
    VAR(UInt_t, genParticles_nPromptMuons) \
    VAR(UInt_t, genParticles_nPromptTaus) \
    VAR(UInt_t, genJets_nTotal) \
    VAR(UInt_t, jets_nTotal_hadronFlavour_b) \
    VAR(UInt_t, jets_nTotal_hadronFlavour_c) \
    VAR(std::vector<LorentzVectorE>, genJets_p4) \
    VAR(std::vector<Int_t>, genJets_hadronFlavour) \
    VAR(LorentzVectorM, genMET_p4) \
    /* Vetos */\
    VAR(Bool_t, extraelec_veto) /* Event is vetoed by the extra electron veto if true */ \
    VAR(Bool_t, extramuon_veto) /* Event is vetoed by the extra muon veto if true */ \
    OTHER_LEPTON_DATA(other_lepton) \
    /* Higgs info */ \
    VAR(std::vector<size_t>, first_daughter_indexes) /* Vector of pair of daughters of Higgses */ \
    VAR(std::vector<size_t>, second_daughter_indexes) /* Vector of pair of daughters of Higgses */ \
    /* Skimmer Variables */ \
    VAR(UInt_t, file_desc_id) /* File id in TupleSkimmer. */ \
    VAR(UInt_t, split_id) /* Split id in TupleSkimmer. */ \
    /* Gen Study Variables */ \
    VAR(Int_t, sample_type)  \
    VAR(Int_t, sample_year) \
    VAR(Int_t, mass_point)  \
    VAR(Int_t, spin)  \
    VAR(Int_t, node)  \
    /* prefiring weight variables */ \
    VAR(double, l1_prefiring_weight) \
    VAR(double, l1_prefiring_weight_up) \
    VAR(double, l1_prefiring_weight_down) \
    /**/

#define VAR(type, name) DECLARE_BRANCH_VARIABLE(type, name)
DECLARE_TREE(ntuple, Event, EventTuple, EVENT_DATA, "events")
#undef VAR

#define VAR(type, name) ADD_DATA_TREE_BRANCH(name)
INITIALIZE_TREE(ntuple, EventTuple, EVENT_DATA)
#undef VAR
#undef EVENT_DATA
#undef LEG_DATA
#undef LVAR
#undef OTHERVAR
#undef JET_DATA
#undef FATJET_DATA
#undef SUBJET_DATA
#undef JET_COMMON_DATA
#undef JVAR
#undef MET_DATA
#undef MVAR
#undef TAU_ID

namespace ntuple {
template<typename T>
constexpr T DefaultFillValue() { return std::numeric_limits<T>::lowest(); }

using ::analysis::operator<<;
using ::analysis::operator>>;

enum class TreeState { Full, Skimmed };
ENUM_NAMES(TreeState) = {
    { TreeState::Full, "Full" }, { TreeState::Skimmed, "Skimmed" }
};

struct LegPair : std::pair<size_t, size_t> {
    LegPair();
    LegPair(size_t _first, size_t _second);
    LegPair(const std::pair<size_t, size_t>& p);

    size_t Get(size_t position) const;
    size_t ToIndex() const;
    bool IsDefined() const;
    bool Contains(size_t i) const;

    static LegPair FromIndex(size_t index);
    static const LegPair Undefined;
};

std::shared_ptr<EventTuple> CreateEventTuple(const std::string& name, TDirectory* directory,
                                             bool readMode, TreeState treeState);
} // namespace ntuple
