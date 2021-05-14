/*
 * All or portions of this file Copyright (c) Amazon.com, Inc. or its affiliates or
 * its licensors.
 *
 * For complete copyright and license terms please see the LICENSE at the root of this
 * distribution (the "License"). All use of this software is governed by the License,
 * or, if provided, by the license below or the license accompanying this file. Do not
 * remove or modify any license notices. This file is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *
 */

#pragma once

#include <Source/AutoGen/CharacterComponent.AutoComponent.h>

namespace MultiplayerSample
{
    class CharacterComponent
        : public CharacterComponentBase
    {
    public:
        AZ_MULTIPLAYER_COMPONENT(MultiplayerSample::CharacterComponent, s_characterComponentConcreteUuid, MultiplayerSample::CharacterComponentBase);

        static void Reflect(AZ::ReflectContext* context);

        void OnInit() override;
        void OnActivate(Multiplayer::EntityIsMigrating entityIsMigrating) override;
        void OnDeactivate(Multiplayer::EntityIsMigrating entityIsMigrating) override;
    };

    class CharacterComponentController
        : public CharacterComponentControllerBase
    {
    public:
        CharacterComponentController(CharacterComponent& parent);

        void OnActivate(Multiplayer::EntityIsMigrating entityIsMigrating) override;
        void OnDeactivate(Multiplayer::EntityIsMigrating entityIsMigrating) override;

        AZ::Vector3 TryMoveToPosition(const AZ::Transform& targetTransform, float deltaTime);
    };
}
