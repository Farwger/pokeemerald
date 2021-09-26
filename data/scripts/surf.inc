EventScript_UseSurf::
	lockall
	checkitem ITEM_SURF_ENGRAM, 1
    compare VAR_RESULT, FALSE
    goto_if_eq EventScript_EndUseSurf
    setitemarg ITEM_SURF_ENGRAM
	msgbox gText_WantToUseSurf, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_ReleaseUseSurf
	dofieldeffect FLDEFF_USE_SURF
EventScript_ReleaseUseSurf::
	releaseall
EventScript_EndUseSurf::
	end
