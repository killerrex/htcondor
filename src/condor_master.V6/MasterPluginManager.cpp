/*
 * Copyright 2008 Red Hat, Inc.
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

#include "condor_common.h"

#include "PluginManager.h"
#include "MasterPlugin.h"

#include "condor_config.h"

void
MasterPluginManager::Initialize()
{
	for (auto plugin: getPlugins()) {
		plugin->initialize();
	}
}

void
MasterPluginManager::Shutdown()
{
	for (auto plugin: getPlugins()) {
		plugin->shutdown();
	}
}

void
MasterPluginManager::Update(const ClassAd *ad)
{
	for (auto plugin: getPlugins()) {
		plugin->update(ad);
	}
}

MasterPlugin::MasterPlugin()
{
    if (PluginManager<MasterPlugin>::registerPlugin(this)) {
		dprintf(D_ALWAYS, "MasterPlugin registration succeeded\n");
	} else {
		dprintf(D_ALWAYS, "MasterPlugin registration failed\n");
	}
}

MasterPlugin::~MasterPlugin() { }


