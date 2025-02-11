	;;--------------------------------------
	;;--------------------------------------
	;; SIMPLE SFX-PLAYER ROUTINE
	;;--------------------------------------
	;; Coded by Conrad/Viruz/Samar/[O]
	;;--------------------------------------
	;; Purposely made for Mr.SID and the C64
	;; conversion game "Prince of Persia"
	;;--------------------------------------
	;; September 2011
	;;--------------------------------------
	;;--------------------------------------

	;;-------------------------
	;; Zero-page address buffer
	;;-------------------------
ZP_SFX_START = ZP_SFX+0
sfx_zp_tmp1 = ZP_SFX+0
sfx_zp_tmp2 = ZP_SFX+1
sfx_zp_tmp_lo = ZP_SFX+2
sfx_zp_tmp_hi = ZP_SFX+3
sfx_zp_playing = ZP_SFX+4
sfx_zp_filtering = ZP_SFX+5
sfx_zp_state_wave_lo = ZP_SFX+6
sfx_zp_state_wave_hi = ZP_SFX+9
sfx_zp_state_filter_lo = ZP_SFX+12
sfx_zp_state_filter_hi = ZP_SFX+13
sfx_zp_tmp3 = ZP_SFX+14
ZP_SFX_END = ZP_SFX+14



	;;-------------------
	;; Player Jump Tables
	;;-------------------
*=BASE_SFX
	;;---------------
	;; Player Routine
	;;---------------
SFX_PLAY
	; Voice section
	ldx #$02				; Loop through all 3 voices
-	lda sfx_zp_state_wave_lo,x		; Set up wave data pointer address
	sta sfx_zp_tmp_lo			;
	lda sfx_zp_state_wave_hi,x		;
	sta sfx_zp_tmp_hi			;
	ldy #$00				; Start at first byte
	lda (sfx_zp_tmp_lo),y			; Read byte 1
	bne +					; If byte != 0, jump to branch.
	lda sfx_zp_playing			; this voice and make it available for
	and sfx_turnoff,x			; another sound effect setup.
	sta sfx_zp_playing			;
	bpl ++++++++++				; Skip to next voice loop
+	sta sfx_zp_tmp2				; Store this as control bits
	stx sfx_zp_tmp1				; Keep a record of X
	lda sfx_voiceoffset,x			; Set X as the SID register offset,
	tax					; depending on which voice processed.
	iny
+	asl sfx_zp_tmp2				; bit 8 set?
	bcc +							
	lda (sfx_zp_tmp_lo),y			; Read byte 2
	sta $d402,x				; Set HIGH PULSE
	iny	
+	asl sfx_zp_tmp2				; bit 7 set?
	bcc +
	lda (sfx_zp_tmp_lo),y			; Read byte 3
	sta $d403,x				; Set LOW PULSE
	iny
+	asl sfx_zp_tmp2				; bit 6 set?
	bcc +
	lda (sfx_zp_tmp_lo),y			; Read byte 4
	sta $d406,x				; Set SUSTAIN/RELEASE
	iny					;
+	asl sfx_zp_tmp2				; bit 5 set?
	bcc +
	lda (sfx_zp_tmp_lo),y			; Read byte 5
	sta $d405,x				; Set ATTACK/DECAY
	iny					;
+	asl sfx_zp_tmp2				; bit 4 set?
	bcc +
	lda (sfx_zp_tmp_lo),y			; Read byte 6
	sta $d400,x				; Set HIGH FREQUENCY
	iny					;
+	asl sfx_zp_tmp2				; bit 3 set?
	bcc +
	lda (sfx_zp_tmp_lo),y			; Read byte 7
	sta $d401,x				; Set LOW FREQUENCY
	iny					;
+	asl sfx_zp_tmp2				; bit 2 set?
	bcc +
	lda (sfx_zp_tmp_lo),y			; Read byte 8
	sta $d404,x				; Set WAVE CONTROL
	iny
+	ldx sfx_zp_tmp1				; Load back in the X state
	tya					; Now set the wave data point address
	clc					; to the new location.
	adc sfx_zp_state_wave_lo,x		; (i.e.  ((OLD LOCATION) + 7 bytes))
	sta sfx_zp_state_wave_lo,x		;
	bcc +					;
	inc sfx_zp_state_wave_hi,x		;
+	dex					; If X >= 0, then loop
	bpl -					;
	
	; Filter section	
	lda sfx_zp_state_filter_lo
	sta sfx_zp_tmp_lo
	lda sfx_zp_state_filter_hi
	sta sfx_zp_tmp_hi
	ldy #$00
	lda (sfx_zp_tmp_lo),y
	beq ++
	sta $d416
	iny
	lda (sfx_zp_tmp_lo),y
	and #$f0
	ora sfx_zp_filtering
	sta $d417
	lda (sfx_zp_tmp_lo),y
	asl
	asl
	asl
	asl
	ora #$0f
	sta $d418
	lda sfx_zp_state_filter_lo
	clc
	adc #$02
	sta sfx_zp_state_filter_lo
	bcc +
	inc sfx_zp_state_filter_hi
+	rts
+	sty sfx_zp_filtering
-	rts	



	;;-------------------------------------
	;; Init Routine
	;;-------------------------------------
	;; A = sfx number ($00-$3f/64 settings)
	;;-------------------------------------
SFX_INIT
	ldx sfx_zp_playing
	ldy sfx_available_voices,x
	beq -
	sty sfx_zp_tmp1
	ldx sfx_voice_configaddress_hi-1,y
	stx sfx_zp_tmp_hi
	ldx sfx_voice_configaddress_lo-1,y
	stx sfx_zp_tmp_lo
	ldy sfx_zp_playing
	ldx sfx_voice_startposition,y
	tay
	lda sfx_lookupindex,y
	tay
	lda sfx_turnon,x
	sta sfx_zp_tmp3
-	dec sfx_zp_tmp1
	bmi +
	lda (sfx_zp_tmp_lo),y
	sta sfx_zp_state_wave_lo,x
	iny
	lda (sfx_zp_tmp_lo),y
	sta sfx_zp_state_wave_hi,x
	iny
	sty sfx_zp_tmp2
	ldy sfx_voiceoffset,x
	lda #$00
	sta $d406,y
	sta $d405,y
	sta $d404,y
	sta $d400,y
	sta $d401,y
	sta $d402,y
	sta $d403,y
	ldy sfx_zp_tmp2
	lda sfx_zp_playing
	ora sfx_turnon,x
	sta sfx_zp_playing
	inx
	cpx #$03
	bne -
	ldx #$00
	beq -	
+	lda sfx_zp_tmp3
	ldx sfx_zp_filtering
	bne +
	sta sfx_zp_filtering
	lda (sfx_zp_tmp_lo),y
	sta sfx_zp_state_filter_lo
	iny
	lda (sfx_zp_tmp_lo),y
	sta sfx_zp_state_filter_hi
+	rts



	;;--------------
	;; Reset Routine
	;;--------------
SFX_RESET
	ldy #0
	sty sfx_zp_filtering
	sty sfx_zp_playing
	lda #3
	sta sfx_zp_tmp1
	lda #<sfx_reset_data
	sta sfx_zp_tmp_lo
	lda #>sfx_reset_data
	sta sfx_zp_tmp_hi
	ldx #$00
	lda sfx_turnon,x
	sta sfx_zp_tmp3
	bpl -

sound_blank = sfx_reset+1	
sfx_reset_data
	.word sound_blank, sound_blank, sound_blank, sound_blank
	

	
	;;---------------------------
	;; Lookup data used by player
	;;---------------------------
sfx_available_voices
	.byte 2,2,2,1,2,1,1
sfx_voice_startposition
	.byte 0,1,2,2,0,1,0
sfx_voiceoffset
	.byte 0,7,14
sfx_turnon
	.byte 1,2,4
sfx_turnoff
	.byte %11111110, %11111101, %11111011
sfx_voice_configaddress_hi
	.byte >sfx_data_lookup_1voice
	.byte >sfx_data_lookup_2voice
sfx_voice_configaddress_lo
	.byte <sfx_data_lookup_1voice
	.byte <sfx_data_lookup_2voice
	
	
	
	;;----------------------
	;; Include SFX byte data
	;;----------------------
.include "sfxdata.asm"
"sfxdata.asm"
The file contains the sound effect data. Please note that this is the first revision of the sound data, meaning that all sounds are not 100% the same to the one's you heard in the released game.

sfx_data_lookup_2voice
	.word sound_footstep, sound_blank, sound_footstep_flt
	.word sound_bump_wall_v1, sound_blank, sound_bump_wall_flt
	.word sound_landing_v1, sound_landing_v2, sound_landing_flt
	.word sound_pressplate_v1, sound_pressplate_v2, sound_pressplate_flt
	.word sound_spikesup_v1, sound_spikesup_v2, sound_spikesup_flt
	.word sound_dooropen_v1, sound_dooropen_v2, sound_dooropen_flt
	.word sound_entranceclose_v1, sound_entranceclose_v2, sound_entranceclose_flt
	.word sound_gaterising_v1, sound_gaterising_v2, sound_gaterising_flt
	.word sound_gateclosing_v1, sound_gateclosing_v2, sound_gateclosing_flt
	.word sound_gateslam_v1, sound_gateslam_v2, sound_gateslam_flt
	.word sound_fallingfloorland_v1, sound_fallingfloorland_v2, sound_fallingfloorland_flt
	.word sound_stabbed_v1, sound_stabbed_v2, sound_stabbed_flt
	.word sound_swordhit_v1, sound_swordhit_v2, sound_swordhit_flt
	.word sound_swordstab_v1, sound_swordstab_v2, sound_swordstab_flt
	.word sound_drink_v1, sound_drink_v2, sound_drink_flt
	.word sound_jumpmirror_v1, sound_jumpmirror_v2, sound_jumpmirror_flt
	.word sound_jawclash_v1, sound_jawclash_v2, sound_jawclash_flt
sfx_data_lookup_2voice_
	
sfx_data_lookup_1voice
	.word sound_footstep, sound_footstep_flt, sound_blank
	.word sound_bump_wall_v1, sound_bump_wall_flt, sound_blank
	.word sound_landing_v1, sound_bump_wall_flt, sound_blank
	.word sound_pressplate_v1, sound_pressplate_flt, sound_blank	
	.word sound_spikesup_v1, sound_spikesup_flt, sound_blank	
	.word sound_dooropen_v1, sound_dooropen_flt, sound_blank
	.word sound_entranceclose_v1, sound_entranceclose_flt, sound_blank
	.word sound_gaterising_v1, sound_gaterising_flt, sound_blank
	.word sound_gateclosing_v1, sound_gateclosing_flt, sound_blank
	.word sound_gateslam_v1, sound_gateslam_flt, sound_blank
	.word sound_fallingfloorland_v1, sound_fallingfloorland_flt, sound_blank
	.word sound_stabbed_v1, sound_stabbed_flt, sound_blank
	.word sound_swordhit_v1, sound_swordhit_flt, sound_blank
	.word sound_swordstab_v1, sound_swordstab_flt, sound_blank
	.word sound_drink_v1, sound_drink_flt, sound_blank
	.word sound_jumpmirror_v1, sound_jumpmirror_v2, sound_jumpmirror_flt, sound_blank
	.word sound_jawclash_v1, sound_jawclash_flt

sfx_lookupindex
	.for i=0,i<17,i=i+1
	.byte i*6
	.next

	
	
	; Jaw-Clash
sound_jawclash_v1
	.byte %00111110
	.word $00f8
	.word $3482
	.byte $09
	.byte %00000010
	.byte $81
	.byte 1,1,1,1,1,1,1
	.byte %00000010
	.byte $80
	.byte 0
sound_jawclash_v2
	.byte %11111110
	.word $0200
	.word $00c8
	.word $2000
	.byte $09
	.byte %00000010
	.byte $57
	.byte 1,1,1,1
	.byte %00001110
	.word $2900
	.byte $10
	.byte 0
sound_jawclash_flt
	.word $f1ff
	.byte 0
	
	
	
	; Jump-Mirror
sound_jumpmirror_v1
	.byte %00111110
	.word $90f7
	.word $0a00
	.byte $09
	.byte %00000010
	.byte $21
	.byte %00001100
	.word $1a10
	.byte %00001100
	.word $1a40
	.byte %00001100
	.word $1a80
	.byte %00001100
	.word $1ac0
	.byte %00001100
	.word $1b00
	.byte %00001100
	.word $1b20	
	.byte %00001100
	.word $1b50	
	.byte %00001100
	.word $1b80	
	.byte %00001100
	.word $1ba0	
	.byte %00000010
	.byte $20
	.byte %00001100
	.word $1b60	
	.byte %00001100
	.word $1b40	
	.byte 0
sound_jumpmirror_v2
	.byte %00111110
	.word $90f7
	.word $2000
	.byte $09
	.byte %00000010
	.byte $15
	.byte %00001100
	.word $2100
	.byte %00001100
	.word $2200
	.byte %00001100
	.word $2300
	.byte %00001100
	.word $2400
	.byte %00001100
	.word $2500
	.byte %00001100
	.word $2600	
	.byte %00001100
	.word $2700	
	.byte %00001100
	.word $2800	
	.byte %00000010
	.byte $14
	.byte %00001100
	.word $2700	
	.byte %00001100
	.word $2600	
	.byte %00001100
	.word $2500	
	.byte %00001100
	.word $2400		
	.byte %00001100
	.word $2300
	.byte %00001100
	.word $2200
	.byte %00001100
	.word $2100
	.byte %00001100
	.word $2000
	.byte 0
sound_jumpmirror_flt
	.word $f510
	.word $f520
	.word $f530
	.word $f540
	.word $f550
	.word $f560
	.word $f570
	.word $f580
	.word $f590
	.word $f5a0
	.word $f5b0
	.word $f5c0
	.word $f5d0
	.word $f5e0
	.word $f5f0	
	.byte 0		
	
	

	; Drink-Poison
sound_drink_v1
	.byte %00111110
	.word $20f2
	.word $1000
	.byte $09
	.byte %00001110
	.word $0700
	.byte $11
	.byte %00001100
	.word $0800
	.byte %00001100
	.word $0900	
	.byte %00001110
	.word $0a70
	.byte $10
	.byte 1,1,1,1,1,1,1
	.byte %00001110
	.word $0a00
	.byte $11
	.byte %00001100
	.word $0b00
	.byte %00001100
	.word $0c00	
	.byte %00001110
	.word $0d00
	.byte $10
	.byte 1,1,1,1,1,1,1
	.byte %00001110
	.word $0c00
	.byte $11
	.byte %00001100
	.word $0d00
	.byte %00001100
	.word $0e00	
	.byte %00001110
	.word $0f00
	.byte $10
	.byte 1,1,1,1,1,1,1
	.byte %00001110
	.word $0e00
	.byte $11
	.byte %00001100
	.word $0f00
	.byte %00001100
	.word $1000	
	.byte %00001110
	.word $1200
	.byte $10
	.byte 1,1,1,1,1,1,1
	.byte %00001110
	.word $1000
	.byte $11
	.byte %00001100
	.word $1200
	.byte %00001100
	.word $1400	
	.byte %00001110
	.word $1500
	.byte $10
	.byte 0
sound_drink_v2
	.byte %00111110
	.word $d012
	.word $1000
	.byte $09
	.byte %00001110
	.word $0810
	.byte $17
	.byte %00001100
	.word $0810
	.byte %00001100
	.word $0910	
	.byte %00001110
	.word $0a10
	.byte $10
	.byte 1,1,1,1,1,1,1
	.byte %00001110
	.word $0a10
	.byte $17
	.byte %00001100
	.word $0b10
	.byte %00001100
	.word $0c10	
	.byte %00001110
	.word $0d10
	.byte $10
	.byte 1,1,1,1,1,1,1
	.byte %00001110
	.word $0c10
	.byte $17
	.byte %00001100
	.word $0d10
	.byte %00001100
	.word $0e10	
	.byte %00001110
	.word $0f10
	.byte $10
	.byte 1,1,1,1,1,1,1
	.byte %00001110
	.word $0e10
	.byte $17
	.byte %00001100
	.word $0f10
	.byte %00001100
	.word $1010	
	.byte %00001110
	.word $1210
	.byte $10
	.byte 1,1,1,1,1,1,1
	.byte %00001110
	.word $1020
	.byte $17
	.byte %00001100
	.word $1220
	.byte %00001100
	.word $1420	
	.byte %00001110
	.word $1520
	.byte $10
	.byte 0
sound_drink_flt
	.word $f104
	.byte 0


	; Sword-Hit
sound_swordhit_v1
	.byte %11111110
	.word $0050
	.word $80f8
	.word $ffff
	.byte $09
	.byte %00000010
	.byte $81
	.byte 1,1,1,1
	.byte %00001110
	.word $3c00
	.byte $41
	.byte 1,1,1,1
	.byte %00000010
	.byte $40
	.byte 0
sound_swordhit_v2
	.byte %11111110
	.word $0010
	.word $0086
	.word $0000
	.byte $09
	.byte %00000010
	.byte $81
	.byte 1,1,1,1
	.byte %00001110
	.word $ffff
	.byte $15
	.byte 1,1,1,1
	.byte %00000010
	.byte $14
	.byte 0
sound_swordhit_flt
	.word $f410
	.word $f411
	.word $f412
	.word $f413
	.word $f414
	.word $f4ff
	.byte 0


	; Sword-Stab
sound_swordstab_v1
	.byte %11111110
	.word $0020
	.word $00f2
	.word $1000
	.byte $09
	.byte %00000010
	.byte $11
	.byte %00001110
	.word $6fff
	.byte $81
	.byte 1
	.byte %00001110
	.word $1000
	.byte $41
	.byte %00001100
	.word $0ff0	
	.byte %00001100
	.word $0f80	
	.byte %00001100
	.word $0f80	
	.byte %00001100
	.word $0e00	
	.byte %00001100
	.word $0d00	
	.byte %00001110
	.word $0c00		
	.byte $40
	.byte %00001100
	.word $0b80	
	.byte %00001100
	.word $0b00	
	.byte 0
sound_swordstab_v2
	.byte %11111110
	.word $0000
	.word $0052
	.word $0000
	.byte $09
	.byte %00000010
	.byte $11
	.byte 1,1,1
	.byte %00001110
	.word $5000
	.byte $57
	.byte 1,1,1,1,1,1
	.byte %00001110
	.word $4000
	.byte $56
	.byte $00
sound_swordstab_flt
	.word $f113
	.word $f113
	.word $f110
	.word $f104	
	.word $f104	
	.word $f240
	.byte 0


	; Stabbed
sound_stabbed_v1
	.byte %00111110
	.word $00f2
	.word $2000
	.byte $09
	.byte %00000010
	.byte $11
	.byte %00001110
	.word $6fff
	.byte $81
	.byte 1
	.byte %00001110
	.word $1000
	.byte $10	
sound_stabbed_v2
	.byte $00
sound_stabbed_flt
	.word $f113
	.word $f113
	.word $f110
	.word $f104	
	.byte 0


	; Falling-Floor-Land
sound_fallingfloorland_v1
	.byte %00111110
	.word $00f8
	.word $0600
	.byte $09
	.byte %00000010
	.byte $81
	.byte 1,1,1,1,1,1
	.byte %00000010
	.byte $80
	.byte 0
sound_fallingfloorland_v2
	.byte %00111110
	.word $00f9
	.word $2000
	.byte $09
	.byte %00000010
	.byte $81
	.byte 1,1,1
	.byte %00000010
	.byte $80
	.byte 0
sound_fallingfloorland_flt
	.word $f110
	.byte 0
	



	

	
	; Footstep
sound_footstep
	.byte %00111110
	.word $1052
	.word $08ff
	.byte $09
	.byte %00000010
	.byte $81
	.byte 1
	.byte %00001110
	.word $0800
	.byte $80
	.byte 0
sound_footstep_flt
	.word $f2ff
	.word $f2c0
	.word $f2ff
	.word $f4c0
	.byte 0


	; Bump Wall
sound_bump_wall_v1
	.byte %11111110
	.word $0780
	.word $0422
	.word $a000
	.byte $09
	.byte %00001110
	.word $2100
	.byte $11	
	.byte %00001110
	.word $1000
	.byte $41
	.byte %00001100
	.word $0f00
	.byte %00001100
	.word $0e00
	.byte %00001100
	.word $0d00
	.byte %00001100
	.word $0c00
	.byte %11001100
	.word $0600
	.word $0b00
	.byte %00101110
	.byte $12
	.word $0a10
	.byte $40
	.byte 0
sound_bump_wall_flt
	.word $8110
	.word $8110
	.word $8308
	.word $8303
	.byte $00


	; Landing
sound_landing_v1
	.byte %11111110
	.word $0780
	.word $00f2
	.word $a000
	.byte $09
	.byte %00000010
	.byte $81
	.byte 1,1,1,1
	.byte %11111110
	.word $0780
	.word $0082
	.word $a000
	.byte $09
	.byte %00001110
	.word $2100
	.byte $11	
	.byte %00001110
	.word $1000
	.byte $41
	.byte %00001100
	.word $0f00
	.byte %00001100
	.word $0e00
	.byte %00001100
	.word $0d00
	.byte %00001100
	.word $0c00
	.byte %11001100
	.word $0600
	.word $0b00
	.byte %00101110
	.byte $12
	.word $0a10
	.byte $40
	.byte 0
sound_landing_v2
	.byte %00111110
	.word $0029
	.word $0100
	.byte $91
	.byte %00000010
	.byte $09
	.byte %00000010
	.byte $81
	.byte 1,1,1,1,1
	.byte %00000010
	.byte $80
	.byte 1,1,1
	.byte %00100000
	.byte $28
	.byte 0
sound_landing_flt
	.word $f115
	.word $f108
	.word $f103
	.word $f103
	.word $f103
	.word $0102
	.byte 0


	; Press Plate
sound_pressplate_v1
	.byte %00111110
	.word $0082
	.word $8000
	.byte $09
	.byte %00000010	
	.byte $81
	.byte 1,1
	.byte %00000010	
	.byte $80
	.byte 0
sound_pressplate_v2
	.byte %00111110
	.word $00e2
	.word $2000
	.byte $09
	.byte %00000010	
	.byte $15
	.byte 1
	.byte %00000010	
	.byte $14
	.byte 0
sound_pressplate_flt
	.word $f130
	.byte 0
	
	
	; Spikes-up
sound_spikesup_v1
	.byte %00111110
	.word $90f5
	.word $ffff
	.byte $09
	.byte %00000010
	.byte $81
	.byte 1,1,1,1,1,1,1,1
	.byte %00001110
	.word $3000
	.byte $80
	.byte 0
sound_spikesup_v2
	.byte %00111110
	.word $90f4
	.word $0c00
	.byte $09
	.byte %00000010
	.byte $81
	.byte 1,1,1,1,1,1,1,1
	.byte %00001110
	.word $0300
	.byte $14
	.byte 0
sound_spikesup_flt
	.word $f1ff
	.word $f1ff
	.word $f1ff
	.word $f1ff
	.word $f1ff
	.word $f1ff
	.word $f1ff
	.word $f1ff
	.word $f408	
	.byte 0
	
	
	; Door-Open
sound_dooropen_v2
	.byte %11111110
	.word $001c
	.word $0076
	.word $2fff
	.byte $09
	.byte %00000010
	.byte $81
	.byte %00001110
	.word $0800
	.byte $11
	.byte %00001100
	.word $0400
	.byte %00001100
	.word $0200
	.byte %00001110
	.word $3000
	.byte $41
	.byte %00001100
	.word $2e00
	.byte %00001100
	.word $2d00
	.byte %00001100
	.word $2c00
	.byte %00001100
	.word $2a00
	.byte %00001100
	.word $2800
	.byte %00001100
	.word $2500	
	.byte %00001100
	.word $2200	
	.byte %00001100
	.word $1e00	
	.byte %00001100
	.word $1800
	.byte %00001100
	.word $1400	
	.byte %00001100
	.word $1000	
	.byte %00001100
	.word $0c00	
	.byte %00001100
	.word $0a00	
	.byte %00001100
	.word $0800	
	.byte %00001100
	.word $0600	
	.byte %00001100
	.word $0400	
	.byte %00001100
	.word $0200	
	.byte 1
	.byte %00000010
	.byte $40
	.byte 0
sound_dooropen_v1
	.byte %11111110
	.word $0008
	.word $d0f8
	.word $1000
	.byte $09
	.byte %00000010
	.byte $81
	.byte 1,1,1,1,1,1,1,1,1,1,1,1
	.byte %00000010
	.byte $80
	.byte 0
sound_dooropen_flt
	.word $f110
	.byte 0
	
	
	; Entrance-Close
sound_entranceclose_v1
	.byte %00111110
	.word $00f9
	.word $ffff
	.byte $91
	.byte %00000010
	.byte $09
	.byte %00000010
	.byte $81
	.byte %00001100
	.word $1600
	.byte %00001100
	.word $0200
	.byte 1,1,1
	.byte %00000010
	.byte $80
	.byte 0
sound_entranceclose_v2
	.byte %00111110
	.word $00f9
	.word $ffff
	.byte $91
	.byte %00000010
	.byte $09
	.byte %00000010
	.byte $81
	.byte %00001100
	.word $1610
	.byte %00001100
	.word $0208
	.byte 1,1,1
	.byte %00000010
	.byte $80
	.byte 0
sound_entranceclose_flt
	.word $f510
	.byte 0
	
	
	; Gate-Rising
sound_gaterising_v1
	.byte %00111110
	.word $0413
	.word $ffff
	.byte $09
	.byte %00000010	
	.byte $81
	.byte %00001100	
	.word $1670
	.byte 1,1,1
	.byte %00000010	
	.byte $80
	.byte 0
sound_gaterising_v2
	.byte %00111110
	.word $0053
	.word $5400
	.byte $09
	.byte %00000010	
	.byte $15
	.byte 1,1
	.byte %00000010	
	.byte $14
	.byte 0
sound_gaterising_flt
	.word $f402
	.byte 0


	; Gate-Closing
sound_gateclosing_v1
	.byte %00111110
	.word $0413
	.word $1fff
	.byte $09
	.byte %00000010	
	.byte $81
	.byte %00001100	
	.word $0a00
	.byte 1,1,1
	.byte %00000010	
	.byte $80
	.byte 0
sound_gateclosing_v2
	.byte %00111110
	.word $0053
	.word $5000
	.byte $09
	.byte %00000010	
	.byte $15
	.byte 1,1
	.byte %00000010	
	.byte $14
	.byte 0
sound_gateclosing_flt
	.word $f402
	.byte 0
	
	
	; Gate-Slam-Shut
sound_gateslam_v1
	.byte %00111110
	.word $50f9
	.word $ffff
	.byte $91
	.byte %00000010
	.byte $09
	.byte %00000010
	.byte $81
	.byte %00001100
	.word $1600
	.byte %00001100
	.word $2800
	.byte 1,1,1
	.byte %00001110
	.word $1800
	.byte $80
	.byte 0
sound_gateslam_v2
	.byte %00111110
	.word $50f9
	.word $ffff
	.byte $91
	.byte %00000010
	.byte $09
	.byte %00000010
	.byte $15
	.byte %00001100
	.word $5510
	.byte %00001100
	.word $2310
	.byte %00001100
	.word $1408
	.byte 1
	.byte %00001110
	.word $1808
	.byte $80
	.byte 0
sound_gateslam_flt
	.word $f1f0
	.word $f1c0
	.word $f180
	.word $f160
	.word $f130
	.word $f110
	.byte 0
"test harness.asm"
An additional program to test the sound effect routine. Coded exclusively for Mr.SID.

	;;-----------------------------------------
	;;-----------------------------------------
	;; SIMPLE SFX-PLAYER TEST HARNESS PROGRAM
	;;-----------------------------------------
	;; Coded by Conrad/Viruz/Samar/[O]
	;;-----------------------------------------
	;; Note: DON'T INCLUDE THIS IN YOUR PROJECT
	;;-----------------------------------------
	;;-----------------------------------------

; Includes
.include "sfxconfig.txt"	; Read config file
.include "sfxplayer.asm"	; Include sfx player code


; Macros
KEYCHECK .macro
	lda #\2
	sta $dc00
	lda $dc01
	eor #\3
	bne +
	ldy #\1
+	
.endm

HEX2STR .macro
	.if \2 = 4
		.if (\1 >> 12)<10
			.byte (\1 >> 12) + $30
		.else
			.byte (\1 >> 12) - 10 + $41	
		.endif
	.fi
	.if \2 >= 3
		.if ((\1 >> 8) & $f)<10
			.byte ((\1 >> 8) & $f) + $30
		.else
			.byte ((\1 >> 8) & $f) - 10 + $41	
		.endif
	.fi
	.if \2 >= 2
		.if ((\1 >> 4) & $f)<10
			.byte ((\1 >> 4) & $f) + $30
		.else
			.byte ((\1 >> 4) & $f) - 10 + $41	
		.endif
	.fi
	.if \2 >= 1		
		.if (\1 & $f)<10
			.byte (\1 & $f) + $30
		.else
			.byte (\1 & $f) - 10 + $41	
		.endif
	.fi
.endm


; Screen
*=$0400
	.text "SFX TESTER       INIT: LDA#--, JSR $"
	#HEX2STR SFX_INIT,4
	.text "----------     PLAY: $"
	#HEX2STR SFX_PLAY,4
	.text ", RESET: $"
	#HEX2STR SFX_RESET,4	
	.text "               ZERO-PAGE BUFFER: $"
	#HEX2STR ZP_SFX_START,2
	.text "-$"
	#HEX2STR ZP_SFX_END,2	
	
	.text "- GREEN BAR REPRESENTS PLAYER RASTERTIME"
	.text "- YELLOW BAR REPRESENTS INIT RASTERTIME "
	.text "- PRESS SPACE TO RESET SFX PLAYER       "
	.text "PRESS THE FOLLOWING KEYS TO TEST SOUNDS:"
	.text "----------------------------------------"
	.text " '0' -> LDA #$00 -> 'FOOTSTEP'          "	
	.text " '1' -> LDA #$01 -> 'BUMP INTO WALL'    "
	.text " '2' -> LDA #$02 -> 'LAND ON GROUND'    "
	.text " '3' -> LDA #$03 -> 'PRESS ON PLATE'    "
	.text " '4' -> LDA #$04 -> 'SPIKES RISE UP'    "	
	.text " '5' -> LDA #$05 -> 'DOOR OPEN'         "	
	.text " '6' -> LDA #$06 -> 'ENTRANCE CLOSE'    "	
	.text " '7' -> LDA #$07 -> 'GATE RISING'       "
	.text " '8' -> LDA #$08 -> 'GATE CLOSING'      "
	.text " '9' -> LDA #$09 -> 'GATE SLAMS SHUT'   "
	.text " 'A' -> LDA #$0A -> 'FALLING FLOOR LAND'"
	.text " 'B' -> LDA #$0B -> 'STABBED'           "
	.text " 'C' -> LDA #$0C -> 'SWORD HIT'         "
	.text " 'D' -> LDA #$0D -> 'SWORD STAB'        "
	.text " 'E' -> LDA #$0E -> 'DRINK POISON'      "
	.text " 'F' -> LDA #$0F -> 'JUMP-THRU-MIRROR'  "
	.text " 'G' -> LDA #$10 -> 'JAW CLASH'         "
	
	
; Run
*=$0803
	sei
	ldx #$00
	stx $d011
	stx $d020
	stx $d021
	lda #$0f
-	sta $d800,x
	sta $d900,x
	sta $da00,x
	sta $db00,x
	inx 
	bne -
	lda #$03
	sta $dd00
	lda #$00
	sta $d015
	lda #$16
	sta $d018
	lda #$06
	sta $d020
	sta $d021
	jsr SFX_RESET
test_loop
	lda #$ff
	sta $dc00
-	bit $d011
	bpl -
-	bit $d011
	bmi -
	lda #$1b
	sta $d011
	lda #$18
-	cmp $d012
	bne -
	dec $d020
	jsr SFX_PLAY
	inc $d020
	ldy #$ff
	#KEYCHECK $09,%11101111,%11111110
	#KEYCHECK $00,%11101111,%11110111
	#KEYCHECK $01,%01111111,%11111110
	#KEYCHECK $02,%01111111,%11110111
	#KEYCHECK $03,%11111101,%11111110
	#KEYCHECK $04,%11111101,%11110111
	#KEYCHECK $0a,%11111101,%11111011
	#KEYCHECK $0e,%11111101,%10111111
	#KEYCHECK $05,%11111011,%11111110
	#KEYCHECK $06,%11111011,%11110111
	#KEYCHECK $0c,%11111011,%11101111
	#KEYCHECK $0d,%11111011,%11111011
	#KEYCHECK $0f,%11111011,%11011111
	#KEYCHECK $07,%11110111,%11111110
	#KEYCHECK $08,%11110111,%11110111
	#KEYCHECK $10,%11110111,%11111011
	#KEYCHECK $0b,%11110111,%11101111
	cpy #$ff
	beq +
pressed
	lda #$00
	beq ++
	lda #$28
-	cmp $d012
	bne -	
	inc $d020
	tya
	jsr SFX_INIT
	dec $d020
	ldy #$00
+	sty pressed+1
+	lda #$7f
	sta $dc00
	lda $dc01
	cmp #$ef
	bne +
	jsr SFX_RESET
+	jmp test_loop