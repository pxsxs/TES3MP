#ifndef COMPONENTS_SETTINGS_H
#define COMPONENTS_SETTINGS_H

#include "categories.hpp"

#include <set>
#include <map>
#include <string>
#include <osg/Vec2f>
#include <osg/Vec3f>

namespace Files
{
    struct ConfigurationManager;
}

namespace Settings
{
    ///
    /// \brief Settings management (can change during runtime)
    ///
    class Manager
    {
    public:
        static CategorySettingValueMap mDefaultSettings;
        static CategorySettingValueMap mUserSettings;

        static CategorySettingVector mChangedSettings;
        ///< tracks all the settings that were changed since the last apply() call

        void clear();
        ///< clears all settings and default settings

        /*
            Start of tes3mp change (major)

            Add a base64encoded argument to this function to allow unencoded files to still be opened
        */
        std::string load(const Files::ConfigurationManager& cfgMgr);
        ///< load settings from all active config dirs. Returns the path of the last loaded file.

        void saveUser (const std::string& file);
        ///< save user settings to file

        static void resetPendingChange(const std::string &setting, const std::string &category);

        static void resetPendingChanges();

        static const CategorySettingVector getPendingChanges();
        ///< returns the list of changed settings and then clears it

        static int getInt (const std::string& setting, const std::string& category);
        static float getFloat (const std::string& setting, const std::string& category);
        static double getDouble (const std::string& setting, const std::string& category);
        static std::string getString (const std::string& setting, const std::string& category);
        static bool getBool (const std::string& setting, const std::string& category);
        static osg::Vec2f getVector2 (const std::string& setting, const std::string& category);
        static osg::Vec3f getVector3 (const std::string& setting, const std::string& category);

        static void setInt (const std::string& setting, const std::string& category, const int value);
        static void setFloat (const std::string& setting, const std::string& category, const float value);
        static void setDouble (const std::string& setting, const std::string& category, const double value);
        static void setString (const std::string& setting, const std::string& category, const std::string& value);
        static void setBool (const std::string& setting, const std::string& category, const bool value);
        static void setVector2 (const std::string& setting, const std::string& category, const osg::Vec2f value);
        static void setVector3 (const std::string& setting, const std::string& category, const osg::Vec3f value);
    };

}

#endif // _COMPONENTS_SETTINGS_H
