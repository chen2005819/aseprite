// Aseprite Document Library
// Copyright (c) 2001-2015 David Capello
//
// This file is released under the terms of the MIT license.
// Read LICENSE.txt for more information.

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "doc/frame_tag.h"

#include "doc/frame_tags.h"

namespace doc {

FrameTag::FrameTag(frame_t from, frame_t to)
  : Object(ObjectType::FrameTag)
  , m_owner(nullptr)
  , m_from(from)
  , m_to(to)
  , m_color(rgba(0, 0, 0, 255))
  , m_name("Tag")
  , m_aniDir(AniDir::FORWARD)
{
}

void FrameTag::setOwner(FrameTags* owner)
{
  ASSERT(!m_owner);
  m_owner = owner;
}

void FrameTag::setFrameRange(frame_t from, frame_t to)
{
  FrameTags* owner = m_owner;
  if (owner)
    owner->remove(this);

  m_from = from;
  m_to = to;

  if (owner)
    owner->add(this); // Re-add the tag, so it's added in the correct place
}

void FrameTag::setName(const std::string& name)
{
  m_name = name;
}

void FrameTag::setColor(color_t color)
{
  m_color = color;
}

void FrameTag::setAniDir(AniDir aniDir)
{
  ASSERT(m_aniDir == AniDir::FORWARD ||
         m_aniDir == AniDir::REVERSE ||
         m_aniDir == AniDir::PING_PONG);

  m_aniDir = aniDir;
}

} // namespace doc
