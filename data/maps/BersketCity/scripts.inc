BersketCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BersketCity_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

BersketCity_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	compare VAR_BERSKET_STATE, 2
	goto_if_eq BersketCity_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
BersketCity_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	compare VAR_BERSKET_STATE, 3
	goto_if_ge BersketCity_MapScripts_MAP_SCRIPT_ON_TRANSITION_5
	return

BersketCity_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
	addobject 2
	setobjectxyperm 5, 24, 16
	setobjectxyperm 4, 23, 17
	setobjectmovementtype 5, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype 4, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype 3, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm 10, 39, 17
	setobjectmovementtype 10, MOVEMENT_TYPE_FACE_UP
	goto BersketCity_MapScripts_MAP_SCRIPT_ON_TRANSITION_1

BersketCity_MapScripts_MAP_SCRIPT_ON_TRANSITION_4:
	setobjectxyperm 3, 30, 18
	return

BersketCity_MapScripts_MAP_SCRIPT_ON_TRANSITION_5:
	goto_if_unset FLAG_HIDE_BERSKET_CITY_LIPS, BersketCity_MapScripts_MAP_SCRIPT_ON_TRANSITION_4
	return


BerksetCity_Sign::
	msgbox BerksetCity_Sign_Text_0, MSGBOX_SIGN
	end


Test::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	setvar VAR_BERSKET_STATE, 1
	end


Construction_Sign::
	msgbox Construction_Sign_Text_0, MSGBOX_SIGN
	end


Lab_Sign::
	msgbox Lab_Sign_Text_0, MSGBOX_SIGN
	end


Tunnel_Sign::
	msgbox Tunnel_Sign_Text_0, MSGBOX_SIGN
	end


Bakery_Sign::
	msgbox Bakery_Sign_Text_0, MSGBOX_SIGN
	end


Cafe_Sign::
	msgbox Cafe_Sign_Text_0, MSGBOX_SIGN
	end


Storage_Sign::
	msgbox Storage_Sign_Text_0, MSGBOX_SIGN
	end


Fearful_Woman::
	compare VAR_BERSKET_STATE, 3
	goto_if_eq Fearful_Woman_3
Fearful_Woman_2:
	msgbox Fearful_Woman_Text_1, MSGBOX_NPC
	end

Fearful_Woman_1:
	msgbox Fearful_Woman_Text_0, MSGBOX_NPC
	end

Fearful_Woman_3:
	compare VAR_LIPS_STATE, 0
	goto_if_eq Fearful_Woman_1
	goto Fearful_Woman_2


Construction_Crew1::
	msgbox Construction_Crew1_Text_0, MSGBOX_NPC
	end


Construction_Crew2::
	msgbox Construction_Crew2_Text_0, MSGBOX_NPC
	end


Guljira::
	compare VAR_BERSKET_STATE, 2
	goto_if_lt Guljira_1
	compare VAR_BERSKET_STATE, 2
	goto_if_ge Guljira_5
Guljira_4:
	compare VAR_BERSKET_STATE, 4
	goto_if_ge Guljira_3
	return

Guljira_1:
	msgbox Guljira_Text_0, MSGBOX_NPC
	return

Guljira_2:
	msgbox Guljira_Text_1, MSGBOX_NPC
	return

Guljira_3:
	msgbox Guljira_Text_2, MSGBOX_NPC
	return

Guljira_5:
	compare VAR_BERSKET_STATE, 4
	goto_if_lt Guljira_2
	goto Guljira_4


BersketCity_EventScript_Rival_Attack::
	setvar VAR_BERSKET_STATE, 2
	end


Keep_Off_Construction_Site::
	lockall
	applymovement 5, Common_Movement_WalkInPlaceFastestRight
	msgbox Keep_Off_Construction_Site_Text_0, MSGBOX_NPC
	applymovement OBJ_EVENT_ID_PLAYER, StepAwayFromConstructionSite
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement 5, Common_Movement_WalkInPlaceFastestDown
	waitmovement 5
	releaseall
	end


BersketCity_EventScript_See_Lips_Left::
	lockall
	call BersketCity_EventScript_See_Lips
	applymovement 3, RunAwayFromLipsLeft
	waitmovement 3
	copyobjectxytoperm 3
	playmoncry SPECIES_GULPIN, 0
	msgbox BersketCity_EventScript_See_Lips_Left_Text_0, MSGBOX_NPC
	releaseall
	end


BersketCity_EventScript_See_Lips_Right::
	lockall
	call BersketCity_EventScript_See_Lips
	applymovement 3, RunAwayFromLipsRight
	waitmovement 3
	copyobjectxytoperm 3
	playmoncry SPECIES_GULPIN, 0
	msgbox BersketCity_EventScript_See_Lips_Left_Text_0
	releaseall
	end


BersketCity_EventScript_See_Lips::
	msgbox BersketCity_EventScript_See_Lips_Text_0
	applymovement 3, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 3
	applymovement 3, Common_Movement_ExclamationMark
	waitmovement 3
	msgbox BersketCity_EventScript_See_Lips_Text_1
	setvar VAR_BERSKET_STATE, 3
	setobjectxyperm 5, 18, 16
	setobjectxyperm 4, 18, 9
	setobjectmovementtype 5, MOVEMENT_TYPE_FACE_DOWN
	setobjectmovementtype 4, MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT
	setobjectxyperm 10, 42, 20
	setobjectmovementtype 10, MOVEMENT_TYPE_WANDER_AROUND
	setobjectmovementtype 3, MOVEMENT_TYPE_FACE_UP_LEFT_AND_RIGHT
	return


BersketCity_EventScript_Meet_Lips::
	lockall
	faceplayer
	compare VAR_LIPS_STATE, 0
	goto_if_eq BersketCity_EventScript_Meet_Lips_2
BersketCity_EventScript_Meet_Lips_1:
	compare VAR_LIPS_STATE, 1
	goto_if_eq BersketCity_EventScript_Meet_Lips_4
	return

BersketCity_EventScript_Meet_Lips_2:
	msgbox BersketCity_EventScript_Meet_Lips_Text_0, MSGBOX_NPC
	setvar VAR_LIPS_STATE, 1
	goto BersketCity_EventScript_Meet_Lips_1

BersketCity_EventScript_Meet_Lips_4:
	msgbox BersketCity_EventScript_Meet_Lips_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq BersketCity_EventScript_Meet_Lips_6
	givemon SPECIES_GULPIN, 9, ITEM_ORAN_BERRY
	compare VAR_RESULT, 0
	goto_if_eq BersketCity_EventScript_Meet_Lips_10
	compare VAR_RESULT, 1
	goto_if_eq BersketCity_EventScript_Meet_Lips_11
	goto Common_EventScript_NoMoreRoomForPokemon
BersketCity_EventScript_Meet_Lips_9:
	releaseall
	end

BersketCity_EventScript_Meet_Lips_6:
	msgbox BersketCity_EventScript_Meet_Lips_Text_2, MSGBOX_NPC
	releaseall
	end

BersketCity_EventScript_Meet_Lips_10:
	call BersketCity_EventScript_Welcome_Lips
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq BersketCity_EventScript_Meet_Lips_16
BersketCity_EventScript_Meet_Lips_15:
	setflag FLAG_HIDE_BERSKET_CITY_LIPS
	setvar VAR_LIPS_STATE, 2
	goto BersketCity_EventScript_Meet_Lips_9

BersketCity_EventScript_Meet_Lips_11:
	call BersketCity_EventScript_Welcome_Lips
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq BersketCity_EventScript_Meet_Lips_19
BersketCity_EventScript_Meet_Lips_18:
	call Common_EventScript_TransferredToPC
	setflag FLAG_HIDE_BERSKET_CITY_LIPS
	setvar VAR_LIPS_STATE, 3
	goto BersketCity_EventScript_Meet_Lips_9

BersketCity_EventScript_Meet_Lips_16:
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto BersketCity_EventScript_Meet_Lips_15

BersketCity_EventScript_Meet_Lips_19:
	call Common_EventScript_NameReceivedBoxMon
	goto BersketCity_EventScript_Meet_Lips_18


BersketCity_EventScript_Welcome_Lips::
	bufferspeciesname 1, SPECIES_GULPIN
	removeobject 2
	playfanfare 4
	setflag FLAG_SYS_POKEMON_GET
	message BersketCity_EventScript_Welcome_Lips_Text_0
	waitmessage
	waitfanfare
	bufferspeciesname 0, SPECIES_GULPIN
	return


BersketCity_EventScript_Tasters_Arrive::
	return


BersketCity_EventScript_Tasters_Depart::
	return


StepAwayFromConstructionSite:
	walk_down
	step_end

RunAwayFromLipsLeft:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_left
	walk_fast_left
	step_end

RunAwayFromLipsRight:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_left
	step_end

BerksetCity_Sign_Text_0:
	.string "Bersket City\nHome of the best food in Hoenn.$"

Construction_Sign_Text_0:
	.string "CONSTRUCTION IN PROGRESS$"

Lab_Sign_Text_0:
	.string "Bersket Lab\nProf. Jacuzzi$"

Tunnel_Sign_Text_0:
	.string "Rusturket Tunnel\nLinking the three cities\pThe tunnel project has been\ncanceled.$"

Bakery_Sign_Text_0:
	.string "Bersket Bakery$"

Cafe_Sign_Text_0:
	.string "Bersket Café$"

Storage_Sign_Text_0:
	.string "Bersket Food Storage\nAUTHORIZED PERSONNEL ONLY$"

Fearful_Woman_Text_0:
	.string "RUN!\pThe Gulpin are back!\nHide your food!$"

Fearful_Woman_Text_1:
	.string "Hello.\pI hope the Gulpin don't come back.$"

Construction_Crew1_Text_0:
	.string "This building was destroyed by Guljira\n"
	.string "in his attack. We're rebuilding it.$"

Construction_Crew2_Text_0:
	.string "We're on break.$"

Guljira_Text_0:
	.string "I'm hungry. Do you have any food?$"

Guljira_Text_1:
	.string "I'm really hungry.\nGet some food for me ... please.$"

Guljira_Text_2:
	.string "You helped get my food?\n"
	.string "Wow, thanks!\p"
	.string "Now that I'm not hungry, I can think\n"
	.string "clearly...\p"
	.string "It was wrong to attack the city, even\n"
	.string "though I was hungry. I should be\l"
	.string "helping people, not stealing their\l"
	.string "food. I'm a Gulpin! I'm Guljira, the\l"
	.string "Guliath, chosen of Swall!$"

Keep_Off_Construction_Site_Text_0:
	.string "Hey, you're not a worker!$"

BersketCity_EventScript_See_Lips_Left_Text_0:
	.string "Gulpin: Sigh$"

BersketCity_EventScript_See_Lips_Text_0:
	.string "Gulpin: Hey, do you know where-$"

BersketCity_EventScript_See_Lips_Text_1:
	.string "Woman: The Gulpin! They're back!$"

BersketCity_EventScript_Meet_Lips_Text_0:
	.string "Hey, you have a Black Diamond?\n"
	.string "I can sense it.\p"
	.string "A Swalot gave you that? Huh.\p"
	.string "Well, I'm Lips. I'm looking for the Sacred\n"
	.string "Ingredients, but everyone here thinks\l"
	.string "I'm after their food! I just want the\l"
	.string "Ingredients.\p"
	.string "You're looking for them too? Can I tag\n"
	.string "along? I'll gulp anyone who tries to\l"
	.string "mess with you!$"

BersketCity_EventScript_Meet_Lips_Text_1:
	.string "Bring Lips on your journey?$"

BersketCity_EventScript_Meet_Lips_Text_2:
	.string "I'll be around a little longer, but I'm\n"
	.string "heading east soon.$"

BersketCity_EventScript_Welcome_Lips_Text_0:
	.string "{PLAYER} recruited Lips!$"
