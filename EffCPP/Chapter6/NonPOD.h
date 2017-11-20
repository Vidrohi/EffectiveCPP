#pragma once
#include <string>

namespace Performance
{
    class NonPODConfig
    {
    private:

        friend class NonPOD;

        std::string m_name;
        float m_value;

    public:

        NonPODConfig(const std::string& name, float value)
            : m_name(name)
            , m_value(value)
        {
            printf("[DEFAULT CONSTRUCTOR] , NonPODConfig [%s] and value [%f] was created \n", m_name.c_str(), m_value);
        }

        NonPODConfig(float value)
            : m_name(std::string("CONSTR_NonPODConfig"))
            , m_value(value)
        {
            printf("[CONSTRUCTOR float], NonPODConfig [%s] and value [%f] was created \n", m_name.c_str(), m_value);
        }
    };

    class NonPOD
    {

    public:
        inline int GetId() const
        {
            return m_id; 
        }

        inline const std::string& GetName() const
        { 
            return m_name; 
        }

        inline float GetValue() const
        { 
            return m_value; 
        }

        void SetName(const std::string& name)
        {
            printf("[NAME CHANGED] , NonPOD %s with id %i and value %f Name changed to %s\n", m_name.c_str(), m_id, m_value , name.c_str());
            m_name = name;
        }

        void SetValue(float value)
        {
            printf("[VALUE CHANGED] , NonPOD %s with id %i and value %f Value changed to %f\n", m_name.c_str(), m_id, m_value, value);
            m_value = value;
        }

        NonPOD()
            : m_id(GetNextId())
            , m_name(std::string("NonPOD"))
            , m_value(0)
        {
            printf("[DEFAULT CONSTRUCTOR] , NonPOD %s with id %i and value %f was created \n", m_name.c_str(), m_id, m_value);
        }

        NonPOD(const std::string& name)
            : m_id(GetNextId())
            , m_name(name)
            , m_value(0)
        {
            printf("[CONSTRUCTOR const std::string&] , NonPOD %s with id %i and value %f was created\n", m_name.c_str(), m_id, m_value);
        }

        NonPOD(const NonPOD& other)
            : m_id(other.m_id)
            , m_name(other.m_name)
            , m_value(other.m_value)
        {
            printf("[COPY CONSTRUCTOR] , NonPOD %s with id %i and value %f was copied\n", other.m_name.c_str() , other.m_id , other.m_value);
        }

        NonPOD(const NonPODConfig& config)
            : m_id(GetNextId())
            , m_name(config.m_name)
            , m_value(config.m_value)
        {
            printf("[CONSTRUCTOR const NonPODConfig&] , NonPOD %s with id %i and value %f was created\n", m_name.c_str(), m_id, m_value);
        }

        void operator=(const NonPOD& other)
        {
            m_name = other.m_name;
            m_value = other.m_value;
            printf("[ASSIGNMENT const NonPOD&] , NonPOD %s with id %i and value %f was assigned\n", m_name.c_str(), m_id, m_value);
        }

        NonPOD operator+(const NonPOD& rhs)
        {
            printf("[ADDITION const NonPOD&] , NonPOD %s with id %i and value %f was added to NonPOD %s with id %i and value %f\n", m_name.c_str(), m_id, m_value, rhs.m_name.c_str(), rhs.m_id, rhs.m_value);

            NonPOD result;
            result.m_value = m_value + rhs.m_value;
            return result;
        }

    private:

        // Id
        unsigned int m_id;

        // Name
        std::string m_name;

        // config Value
        float m_value;

        static unsigned int s_currentId;
        static unsigned int GetNextId();
    };
}
