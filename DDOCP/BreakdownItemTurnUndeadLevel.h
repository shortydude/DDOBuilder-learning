// BreakdownItemTurnUndeadLevel.h
//
#pragma once
#include "BreakdownItem.h"

class BreakdownItemTurnUndeadLevel:
        public BreakdownItem
{
    public:
        BreakdownItemTurnUndeadLevel(
                BreakdownType type,
                MfcControls::CTreeListCtrl * treeList,
                HTREEITEM hItem);
        virtual ~BreakdownItemTurnUndeadLevel();

        // required overrides
        virtual CString Title() const override;
        virtual CString Value() const override;
        virtual void CreateOtherEffects() override;
        virtual bool AffectsUs(const Effect & effect) const override;
    private:
        // CharacterObserver overrides
        virtual void UpdateClassChanged(Character * charData, ClassType classFrom, ClassType classTo, size_t level) override;

        // BreakdownObserver overrides
        virtual void UpdateTotalChanged(BreakdownItem * item, BreakdownType type) override;

        bool IsUs(const Effect & effect) const;
};
