#ifndef EVENT_H
#define EVENT_H

#include "BaseFiller.h"
#include "PandaProd/Objects/interface/PEvent.h"

#include <map>
#include <string>

namespace panda {
class EventFiller : virtual public BaseFiller
{
    public:
        EventFiller(TString n);
        ~EventFiller();
        int analyze(const edm::Event& iEvent);
        virtual inline string name(){return "EventFiller";};
        void init(TTree *t);

        bool minimal=false;

        edm::EDGetTokenT<GenEventInfoProduct> gen_token;
        edm::Handle<GenEventInfoProduct> gen_handle;
        
        // vertices
        edm::Handle<reco::VertexCollection> vtx_handle;
        edm::EDGetTokenT<reco::VertexCollection> vtx_token;
        const reco::Vertex *pv() const { return pvtx; }

        // triggers
        std::vector<std::string> trigger_paths;
        edm::Handle< edm::TriggerResults  > trigger_handle;
        edm::EDGetTokenT< edm::TriggerResults > trigger_token;

        // met filters
        std::vector<std::string> metfilter_paths;

        edm::EDGetTokenT<bool> badchcand_token;
        edm::Handle<bool> badchcand_handle;

        edm::EDGetTokenT<bool> badpfmuon_token;
        edm::Handle<bool> badpfmuon_handle;

        edm::EDGetTokenT<edm::TriggerResults> metfilter_token;
        edm::Handle<edm::TriggerResults> metfilter_handle;
    private:
        const reco::Vertex *pvtx;
        panda::PEvent *data;
        TString treename;
};
}


#endif
