/**
 * FreeRDP: A Remote Desktop Protocol Implementation
 *
 * Copyright 2014 Marc-Andre Moreau <marcandre.moreau@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef FREERDP_SHADOW_SERVER_ENCODER_H
#define FREERDP_SHADOW_SERVER_ENCODER_H

#include <winpr/crt.h>
#include <winpr/stream.h>

#include <freerdp/freerdp.h>
#include <freerdp/codec/rfx.h>
#include <freerdp/codec/nsc.h>
#include <freerdp/codec/bitmap.h>

#include <freerdp/server/shadow.h>

struct rdp_shadow_encoder
{
	rdpShadowServer* server;

	BYTE* data;
	int width;
	int height;
	int scanline;

	UINT32 bitsPerPixel;
	UINT32 bytesPerPixel;

	BYTE** grid;
	int gridWidth;
	int gridHeight;
	BYTE* gridBuffer;
	int maxTileWidth;
	int maxTileHeight;

	wStream* rfx_s;
	RFX_CONTEXT* rfx;

	wStream* nsc_s;
	NSC_CONTEXT* nsc;

	wStream* bs;
	wStream* bts;
	BITMAP_PLANAR_CONTEXT* planar;

	int fps;
	int maxFps;
	BOOL frameAck;
	UINT32 frameId;
	wListDictionary* frameList;
};

#ifdef __cplusplus
extern "C" {
#endif

int shadow_encoder_reset(rdpShadowEncoder* encoder);
int shadow_encoder_create_frame_id(rdpShadowEncoder* encoder);

rdpShadowEncoder* shadow_encoder_new(rdpShadowServer* server);
void shadow_encoder_free(rdpShadowEncoder* encoder);

#ifdef __cplusplus
}
#endif

#endif /* FREERDP_SHADOW_SERVER_ENCODER_H */
